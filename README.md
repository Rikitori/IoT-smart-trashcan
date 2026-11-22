# 🗑️ HỆ THỐNG THÙNG RÁC THÔNG MINH PHÂN LOẠI TỰ ĐỘNG

Dự án nghiên cứu và chế tạo **Hệ thống thùng rác thông minh** ứng dụng vi điều khiển Arduino Uno R3, có khả năng tự động phát hiện vật thể tiếp cận và phân loại rác thải thành **Rác Khô** và **Rác Ướt** dựa trên cảm biến độ ẩm.

---

## 📌 1. Giới thiệu chung
Phân loại rác thải tại nguồn là bước quan trọng giúp tối ưu hóa quy trình xử lý rác và bảo vệ môi trường. Dự án cung cấp giải pháp thu gom và phân loại rác tự động với chi phí thấp, vận hành ổn định, dễ lắp đặt và có khả năng mở rộng lên các hệ thống giám sát môi trường thông minh.

---

## 🏗️ 2. Cấu trúc Thư mục Repository
Cấu trúc lưu trữ tài nguyên của dự án trên GitHub được tổ chức mô-đun hóa:

```
├── code/
│   └── Smart_Trash_Collector.ino   # Mã nguồn C++ lập trình trên Arduino IDE
├── libraries/                      # Thư viện phụ trợ (Servo.h)
├── poster/
│   └── Poster_A4.pdf               # Poster báo cáo dự án khổ A4
├── docs/
│   ├── so_do_nguyen_ly_khong_lcd.png # Sơ đồ nguyên lý kết nối phần cứng
│   └── BAO_CAO_HE_THONG_NHUNG_THUNG_RAC_THONG_MINH.docx # Báo cáo chi tiết
└── README.md                       # Tài liệu hướng dẫn & giới thiệu dự án
```

---

## 🛠️ 3. Kiến trúc Phần cứng & Bảng Kết nối Chân
Hệ thống sử dụng các linh kiện phần cứng tiêu chuẩn được điều khiển trung tâm bởi Arduino Uno R3:

| Linh kiện / Mô-đun | Chân kết nối (Arduino Uno) | Chức năng chính |
| :--- | :--- | :--- |
| **Arduino Uno R3** | Vi điều khiển trung tâm | Đọc cảm biến, xử lý thuật toán phân loại & điều khiển cơ cấu |
| **HC-SR04 (Siêu âm)** | Trig: `Pin 12`, Echo: `Pin 11` | Đo khoảng cách phát hiện vật thể `< 15cm` |
| **Cảm biến độ ẩm đất** | Analog Output: `Pin A0` | Đọc chỉ số độ ẩm của rác thải |
| **Động cơ Servo SG90** | Signal: `Pin 8` | Cơ cấu phân loại: Xoay 0° (Rác Khô), 180° (Rác Ướt), 90° (Vị trí chờ) |

---

## ⚡ 4. Nguyên lý Hoạt động & Thuật toán
1. **Đo khoảng cách (HC-SR04):**
   - Cảm biến siêu âm thực hiện 2 lần đo mẫu liên tiếp để lấy giá trị trung bình khoảng cách `distance`.
   - Điều kiện kích hoạt: Khoảng cách nằm trong dải `1 cm < distance < 15 cm` (`Ultra_Distance = 15`).

2. **Đọc và khử nhiễu độ ẩm:**
   - Đọc giá trị Analog từ chân `A0` 3 lần liên tiếp.
   - Hàm `constrain(soil, 485, 1023)` và `map(soil, 485, 1023, 100, 0)` chuyển đổi tín hiệu cảm biến sang phần trăm độ ẩm `0% - 100%`.
   - Tính độ ẩm trung bình `fsoil`.

3. **Phân loại & Thực thi cơ cấu:**
   - **Nếu `fsoil > maxDryValue (20%)`:** Xác định là **RÁC ƯỚT**. Động cơ Servo quay góc **180°**, giữ vị trí 3 giây để rác rơi vào ngăn rác ướt.
   - **Nếu `fsoil <= maxDryValue (20%)`:** Xác định là **RÁC KHÔ**. Động cơ Servo quay góc **0°**, giữ vị trí 3 giây để rác rơi vào ngăn rác khô.
   - **Tái lập vị trí:** Đưa Servo về góc ban đầu **90°** và chờ lượt tiếp theo.

---

## 🚀 5. Hướng dẫn Cài đặt & Vận hành
1. **Tải dự án về máy:**
   ```bash
   git clone https://github.com/<username>/<repo-name>.git
   ```
2. **Nạp code trên Arduino IDE:**
   - Mở phần mềm Arduino IDE, chọn loại Board là **Arduino Uno** và cổng COM kết nối.
   - Mở file `code/Smart_Trash_Collector.ino` và bấm **Upload**.
3. **Theo dõi Serial Monitor:**
   - Mở Serial Monitor ở tốc độ Baudrate `9600`.
   - Xem dữ liệu phản hồi thời gian thực: Khoảng cách, % độ ẩm và trạng thái phân loại (*Dang phan loai: RAC UOT* / *Dang phan loai: RAC KHO*).

---

## 🔮 6. Hướng phát triển trong tương lai
- **Kết nối IoT & Dashboard:** Tích hợp mô-đun ESP8266/ESP32 để đẩy dữ liệu tràn thùng rác và số lượng rác phân loại lên trang quản lý Web/Blynk.
- **Nhận diện bằng AI/Computer Vision:** Sử dụng camera AI để phân loại rác tái chế (nhựa, kim loại, giấy).

---

## 🤝 7. Thành viên Đóng góp
| Họ và Tên | Vai trò / Nhiệm vụ |
| :--- | :--- |
| **[Thành viên 1]** | Lập trình thuật toán C++ & Cấu hình Arduino |
| **[Thành viên 2]** | Thiết kế sơ đồ nguyên lý & Lắp ráp phần cứng |
| **[Thành viên 3]** | Thực nghiệm mô hình & Trình bày báo cáo / Poster |

---
*Dự án thực hiện trong khuôn khổ báo cáo đánh giá học phần Hệ thống Nhúng.*
