#include <Servo.h>

Servo servo1;

const int trigPin = 12;
const int echoPin = 11;
const int potPin = A0;

long duration;
int distance = 0;

int soil = 0;
int fsoil = 0;

int maxDryValue = 20;
int Ultra_Distance = 15;

void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.attach(8);

  // Đưa Servo về vị trí ban đầu
  servo1.write(90);

  Serial.println("HE THONG PHAN LOAI RAC");
  Serial.println("San sang hoat dong!");
}

void loop()
{
  distance = 0;

  // Đo khoảng cách bằng cảm biến HC-SR04
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(7);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH, 30000);

    distance += duration * 0.034 / 2;

    delay(10);
  }

  distance = distance / 2;

  // Kiểm tra xem có rác ở gần hay không
  if (distance < Ultra_Distance && distance > 1)
  {
    Serial.println("Phat hien rac!");

    delay(1000);

    // Đọc cảm biến độ ẩm 3 lần
    fsoil = 0;

    for (int i = 0; i < 3; i++)
    {
      soil = analogRead(potPin);

      soil = constrain(soil, 485, 1023);

      fsoil += map(soil, 485, 1023, 100, 0);

      delay(75);
    }

    fsoil = fsoil / 3;

    Serial.print("Do am: ");
    Serial.print(fsoil);
    Serial.println("%");

    // Phân loại rác
    if (fsoil > maxDryValue)
    {
      Serial.println("Dang phan loai: RAC UOT");

      servo1.write(180);
      delay(3000);
    }
    else
    {
      Serial.println("Dang phan loai: RAC KHO");

      servo1.write(0);
      delay(3000);
    }

    // Đưa Servo về vị trí ban đầu
    servo1.write(90);

    Serial.println("Hoan tat phan loai!");
    Serial.println("--------------------");

    delay(1000);
  }
}
