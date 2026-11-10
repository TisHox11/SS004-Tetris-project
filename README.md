# SS006 Tetris Project - Game Tetris Console (C++)

Dự án trò chơi **Tetris** chạy trên giao diện Console Windows bằng ngôn ngữ C++, được xây dựng và nâng cấp dựa trên khung code mẫu của **Thầy Toàn** theo quy trình phát triển 4 giai đoạn (Pipeline).

## Tính năng nổi bật

* **Hiển thị mượt mà:** Sử dụng kỹ thuật dịch chuyển con trỏ `gotoXY()` và ẩn con trỏ `hideCursor()` (thư viện `<windows.h>`) giúp vẽ đè khung hình, khắc phục hoàn toàn hiện tượng chớp nháy màn hình của `system("cls")`.
* **Cơ chế gạch chuẩn xác:** Đầy đủ 7 khối gạch cổ điển (`I`, `O`, `T`, `S`, `Z`, `J`, `L`) với 4 góc xoay ($0^\circ, 90^\circ, 180^\circ, 270^\circ$), hỗ trợ rơi nhanh từng ô và rơi thẳng chạm đáy (*Hard Drop*).
* **Hệ thống điểm & độ khó tự động:** Cộng điểm thưởng theo combo số hàng xóa được cùng lúc, tự động tăng cấp độ (*Level*) và tăng tốc độ rơi khi đạt mốc điểm.
* **Giao diện trực quan:** Có màn hình chờ (*Start Menu*), bảng thông tin bên cạnh bàn cờ hiển thị Điểm, Cấp độ, Khối gạch tiếp theo (*Next Block*), tính năng Tạm dừng (*Pause*) và màn hình Kết thúc (*Game Over*).

## Phím điều khiển

| Phím bấm | Chức năng |
| :--- | :--- |
| **`A`** / **`D`** | Di chuyển khối gạch sang Trái / Phải |
| **`W`** | Xoay khối gạch $90^\circ$ |
| **`X`** | Hạ nhanh khối gạch xuống 1 ô (*Soft Drop*) |
| **`Space`** | Hạ khối gạch rơi thẳng chạm đáy (*Hard Drop*) |
| **`P`** | Tạm dừng / Tiếp tục trò chơi (*Pause*) |
| **`Q`** | Thoát trò chơi |

## Quy trình phát triển (4-Stage Pipeline)

1. **Giai đoạn 1 - Khởi tạo & Hiển thị Console:** Thiết lập bảng chơi `initBoard()`, chống nháy màn hình với `gotoXY()`, `hideCursor()` và khởi tạo thông số ván đấu `initGame()`.
2. **Giai đoạn 2 - Cơ chế Khối gạch (Core Gameplay):** Xử lý va chạm `canMove()`, sinh gạch mới `spawnBlock()`, xoay gạch `canRotate()`, `rotateBlock()` và hạ gạch nhanh `hardDrop()`.
3. **Giai đoạn 3 - Luật chơi, Điểm số & Độ khó:** Xóa hàng đầy `removeLine()`, tính điểm & tăng tốc độ rơi `updateScoreAndLevel()`, kiểm tra điều kiện thua `isGameOver()`.
4. **Giai đoạn 4 - Điều khiển & Giao diện (UI):** Tách bộ xử lý phím `handleInput()`, vẽ giao diện phụ `drawUI()`, màn hình `showMenu()`, `pauseGame()` và `showGameOver()`.

## Hướng dẫn biên dịch và chạy game

Trò chơi sử dụng thư viện `<conio.h>` và `<windows.h>`, tương thích tốt nhất trên hệ điều hành **Windows** (VS Code, Dev-C++, Code::Blocks, Visual Studio).

Chạy bằng Terminal / Git Bash (với trình biên dịch MinGW G++):

    1. Biên dịch mã nguồn
    g++ main.cpp -o tetris.exe

    2. Chạy trò chơi
    ./tetris.exe
