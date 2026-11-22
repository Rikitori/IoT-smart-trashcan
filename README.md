# 🗑️ HỆ THỐNG THÙNG RÁC THÔNG MINH PHÂN LOẠI TỰ ĐỘNG - NHÓM 13

Dự án nghiên cứu và chế tạo **Hệ thống thùng rác thông minh** ứng dụng vi điều khiển Arduino, có khả năng tự động phát hiện vật thể và phân loại rác thải thành **Rác Khô** và **Rác Ướt** dựa trên cảm biến độ ẩm.

---

## 👥 Thành viên Đóng góp (Nhóm 13)
* **Lê Đức Minh** - *Nhóm trưởng*: Lập trình thuật toán C++, tích hợp phần cứng & điều phối dự án.
* **Bùi Xuân Trường** - *Thành viên*: Thiết kế sơ đồ nguyên lý mạch, thực nghiệm phần cứng & báo cáo.

---

## 📌 1. Giới thiệu chung
Phân loại rác thải tại nguồn là bước quan trọng giúp tối ưu hóa quy trình xử lý rác và bảo vệ môi trường. Dự án cung cấp giải pháp thu gom và phân loại rác tự động với chi phí thấp, vận hành ổn định và dễ dàng nâng cấp lên các hệ thống giám sát thông minh.

---

## 🏗️ 2. Cấu trúc Thư mục Repository
Cấu trúc lưu trữ tài nguyên của dự án trên GitHub được tổ chức rõ ràng theo chuẩn mô-đun:

```
├── code/
│   └── Smart_Trash_Collector.ino   # Mã nguồn C++ lập trình trên Arduino IDE
├── libraries/                      # Các thư viện hỗ trợ (Servo.h)
├── poster/
│   └── Poster_A4.pdf               # Poster báo cáo dự án khổ A4 (Nhóm 13)
├── docs/
│   ├── so_do_nguyen_ly_khong_lcd.png # Sơ đồ nguyên lý kết nối phần cứng
│   └── BAO_CAO_HE_THONG_NHUNG_THUNG_RAC_THONG_MINH.docx # Báo cáo học phần
└── README.md                       # Tài liệu hướng dẫn và giới thiệu dự án
```

---

## 🛠️ 3. Kiến trúc Phần cứng & Bảng Kết nối Chân
Hệ thống được thiết kế theo mô hình xử lý phần cứng tập trung với vi điều khiển Arduino:

| Linh kiện / Mô-đun | Chân kết nối (Arduino Uno) | Chức năng chính |
| :--- | :--- | :--- |
| **Arduino Uno R3** | Vi điều khiển trung tâm | Xử lý thuật toán đọc cảm biến và điều khiển cơ cấu |
| **HC-SR04 (Siêu âm)** | Trig: `Pin 12`, Echo: `Pin 11` | Phát hiện rác ở khoảng cách `< 15cm` |
| **Cảm biến độ ẩm đất** | Analog: `Pin A0` | Đọc chỉ số độ ẩm vật thể để phân loại |
| **Động cơ Servo SG90** | PWM: `Pin 8` | Gạt rác về ngăn Rác Khô (0°) hoặc Rác Ướt (180°) |

---

## ⚡ 4. Nguyên lý Hoạt động & Thuật toán
1. **Phát hiện vật thể:** Cảm biến siêu âm HC-SR04 liên tục đo khoảng cách. Khi có rác lại gần trong khoảng `1 cm < distance < 15 cm`, hệ thống kích hoạt quy trình phân loại.
2. **Xử lý tín hiệu độ ẩm:** Cảm biến độ ẩm đọc giá trị Analog 3 lần liên tiếp tại `A0`, ánh xạ giá trị (`map`) và lấy trung bình (`fsoil`) để loại bỏ nhiễu tín hiệu.
3. **Phân loại & Thực thi cơ cấu:**
   - Nếu `fsoil > 20%`: Xác định là **RÁC ƯỚT** ➔ Servo quay góc **180°** (giữ trong 3 giây).
   - Nếu `fsoil <= 20%`: Xác định là **RÁC KHÔ** ➔ Servo quay góc **0°** (giữ trong 3 giây).
4. **Tái lập vị trí:** Sau khi phân loại xong, Servo tự động quay về góc **90°** (vị trí cân bằng ban đầu) để chờ lượt tiếp theo.

---

## 🚀 5. Hướng dẫn Cài đặt & Vận hành
1. Tải repository về máy hoặc sử dụng lệnh:
   ```bash
   git clone https://github.com/<username>/<repo-name>.git
   ```
2. Khởi động phần mềm **Arduino IDE** và kết nối board Arduino Uno với máy tính qua cổng USB.
3. Mở file `code/Smart_Trash_Collector.ino`, chọn đúng loại Board (*Arduino Uno*) và Cổng COM tương ứng.
4. Biên dịch và nạp chương trình vào vi điều khiển.
5. Mở **Serial Monitor** với tốc độ baud `9600` để theo dõi khoảng cách, chỉ số % độ ẩm và trạng thái phân loại theo thời gian thực.

---

## 🔮 6. Hướng phát triển trong tương lai
- **Tích hợp IoT Dashboard:** Gửi dữ liệu về mức độ đầy rác và thống kê số lượng rác phân loại lên giao diện Web thông qua giao thức MQTT.
- **Nhận diện bằng AI:** Tích hợp camera FPV và thuật toán xử lý ảnh AI để nhận diện các loại rác tái chế, nhựa và kim loại.

---
*Dự án thực hiện bởi Nhóm 13 trong khuôn khẩu báo cáo đánh giá học phần Hệ thống Nhúng.*
---
*Dự án thực hiện bởi Nhóm 13 trong khuôn khẩu báo cáo đánh giá học phần Hệ thống Nhúng.*
