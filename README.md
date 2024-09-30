1. Chức năng

    - Tính toán cơ bản: nhập, xuất giá trị, thực hiện các phép toán số học

    - Lưu trữ giá trị

2. Flow chương trình
    
    - Khi 1 sự kiện bên ngoài xảy ra, 1 message sẽ được thêm vào message queue của hệ điều hành

    - MessageLoop của chương trình nhận message từ hệ điều hành, sau đó chuyển lại cho hệ điều hành  để xử lý

    - Hệ điều hành sẽ gọi đến procedure tương ứng mà chương trình đã đăng ký

3. Ưu điểm và nhược điểm của mô hình Event-driven

    Ưu điểm:

        - Phản ứng linh hoạt

        - Hiệu suất cao

        - Tích hợp dễ dàng

        - Kịp thời và chính xác

    Nhược điểm:

        - Phức tạp trong việc quản lý luồng

        - Khó theo dõi luồng logic

        - Khả năng xảy ra lỗi

        - Đồng bộ hóa khó khăn
