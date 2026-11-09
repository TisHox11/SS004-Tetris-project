#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
#define H 20
#define W 15
char board[H][W] = {};

int x, y, b;
char blocks[][4][4] ={
        {{' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '}},
        {{' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'I','I','I','I'},
         {' ',' ',' ',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','T',' ',' '},
         {'T','T','T',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','S','S',' '},
         {'S','S',' ',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'Z','Z',' ',' '},
         {' ','Z','Z',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'J',' ',' ',' '},
         {'J','J','J',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ',' ','L',' '},
         {'L','L','L',' '},
         {' ',' ',' ',' '}}
};

bool canMove(int dx, int dy); // Kiem tra khoi gach co di chuyen duoc theo (dx, dy)
void block2Board(); // Ghi khoi gach hien tai vao mang board
void boardDelBlock(); // Xoa khoi gach hien tai khoi mang board
void initBoard(); // Khoi tao khung tuong bao quanh bang board
void draw(); // Ve bang game ra man hinh console
void removeLine(); // Kiem tra va xoa cac hang da duoc lap day

void gotoXY(int posX, int posY); // Dua con tro man hinh den toa do (posX,posY)
void hideCursor(); // An con tro nhap nhay tren man hinh console
void initGame(); // Khoi tao thong so ban dau cua van choi
void spawnBlock(); // Sinh khoi gach moi tai dinh man hinh
bool canRotate(int newBlockIndex); // Kiem tra khoi gach co xoay sang trang thai moi duoc khong
void rotateBlock(); // Thuc hien xoay khoi gach khi nhan phim
void hardDrop(); // Ha khoi gach roi cham day ngay lap tuc
void handleInput(bool &isRunning); // Xu ly toan bo su kien nhan phim tu nguoi choi
void updateScoreAndLevel(int linesCount); // Cap nhat diem so, cap do va toc do roi
bool isGameOver(); // Kiem tra dieu kien ket thuc game (thua cuoc)
void drawUI(); // Ve giao dien diem so, khoi tiep theo ben canh bang
void pauseGame(); // Tam dung tro choi khi nhan phim Pause
void showMenu(); // Hien thi man hinh Menu bat dau game
void showGameOver(); // Hien thi man hinh ket thuc va bao tong diem


int main()
{
    srand(time(0));
    x = 5; y = 0; b = rand()%7;
    initBoard();
    while (1){
        boardDelBlock();
        if (kbhit()){
            char c = getch();
            if (c == 'a' && canMove(-1,0)) x--;
            if (c == 'd' && canMove( 1,0)) x++;
            if (c == 'x' && canMove( 0,1)) y++;
            if (c == 'q') break;
        }
        if (canMove(0,1)) y++;
        else{
            block2Board();
            removeLine();
            x = 5; y = 0; b = rand()%7;
        }
        block2Board();
        draw();
        _sleep(500);
    }
    return 0;
}

bool canMove(int dx, int dy){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ') {
                int xt = x + j + dx;
                int yt = y + i + dy;
                if (xt < 1 || xt >= W-1 || yt >= H-1 ) return false;
                if (board[yt][xt] != ' ') return false;
            }
    return true;
}
void block2Board(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ')
                board[y+i][x+j] = blocks[b][i][j];
}
void boardDelBlock(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ')
                board[y+i][x+j] = ' ';
}
void initBoard(){
    for (int i = 0 ; i < H ; i++)
        for (int j = 0 ; j < W ; j++)
            if (i == 0 || i == H-1 || j ==0 || j == W-1) board[i][j] = '#';
            else board[i][j] = ' ';
}
void draw(){
    system("cls");

    for (int i = 0 ; i < H ; i++, cout<<endl)
        for (int j = 0 ; j < W ; j++) cout<<board[i][j];
}
void removeLine(){
    int i,j;
    for (i = H-2 ; i > 0 ; i-- ){
        for (j = 0 ; j < W ; j++)
            if (board[i][j] == ' ') break;
        if (j == W){
            for (int ii = i ; ii > 0 ; ii--)
                for (int jj = 0; jj < W; jj++)
                    board[ii][jj] = board[ii-1][jj];
            i++;
            draw();
            _sleep(200);
        }
    }
}

void gotoXY(int posX, int posY) {
// Chuc nang: Dua con tro van ban tren cua so Console den toa do cot posX, hang posY.
// Su dung de: Ve de khung hinh moi len khung hinh cu ma khong can xoa trang man hinh,
// giup game chay muot va khong bi chop nhay.
}

void hideCursor() {
// Chuc nang: An dau nhay con tro soan thao tren man hinh Console.
// Su dung de: Goi mot lan luc khoi tao game nham tang tinh tham my cho giao dien.
}

void initGame() {
// Chuc nang: Thiet lap lai toan bo thong so van dau (score = 0, level = 1, dropSpeed = 500),
// dong thoi goi ham initBoard() va hideCursor() de chuan bi mat bang choi.
// Su dung de: Goi truoc khi buoc vao vong lap chinh hoac khi bat dau van moi.
}

void spawnBlock() {
// Chuc nang: Dat lai toa do xuat phat cho khoi gach moi tai dinh man hinh (x = 5, y = 0),
// gan khoi gach hien tai b bang nextB, va sinh ngau nhien chi so moi cho nextB.
// Su dung de: Goi luc moi vao game va goi moi khi khoi gach truoc do da cham day.
}

bool canRotate(int newBlockIndex) {
// Chuc nang: Kiem tra xem tai vi tri (x, y) hien tai, neu thay doi hinh dang khoi gach
// sang trang thai xoay moi (newBlockIndex) thi co bi vuot bien hoac cham gach cu khong.
// Su dung de: Lam dieu kien kiem tra an toan ben trong ham rotateBlock().
    return false;
}

void rotateBlock() {
// Chuc nang: Xac dinh chi so hinh dang tiep theo cua khoi gach hien tai khi xoay 90 do,
// goi ham canRotate() de kiem tra, neu hop le thi cap nhat bien b sang hinh dang moi.
// Su dung de: Goi khi nguoi choi nhan phim xoay gach (vi du phim 'w').
}

void hardDrop() {
// Chuc nang: Su dung vong lap kiem tra canMove(0, 1) lien tuc de tang tung do y
// cho den khi khoi gach cham sat be mat thap nhat co the ngay trong 1 nhip.
// Su dung de: Goi khi nguoi choi nhan phim Space muon ha nhanh khoi gach.
}

void handleInput(bool &isRunning) {
// Chuc nang: Doc ky tu phim vua nhan bang getch() va dieu huong xu ly:
// - Phim 'a': Neu canMove(-1, 0) dung thi giam x (sang trai).
// - Phim 'd': Neu canMove(1, 0) dung thi tang x (sang phai).
// - Phim 'x': Neu canMove(0, 1) dung thi tang y (roi nhanh 1 o).
// - Phim 'w': Goi ham rotateBlock() de xoay khoi gach.
// - Phim Space: Goi ham hardDrop() de roi cham day.
// - Phim 'p': Goi ham pauseGame() de tam dung.
// - Phim 'q': Gan isRunning = false de thoat game.
// Su dung de: Tach toan bo thao tac dieu khien cua nguoi choi thanh mot ham doc lap.
 }

void updateScoreAndLevel(int linesCount) {
// Chuc nang: Tinh diem thuong dua tren so hang xoa duoc cung luc (linesCount),
// cong don vao bien score; neu diem vuot moc thi tang level va giam dropSpeed.
// Su dung de: Goi khi nguoi choi xoa duoc hang trong ham removeLine().
}

bool isGameOver() {
// Chuc nang: Kiem tra ngay tai thoi diem khoi gach moi vua sinh ra o dinh (x = 5, y = 0),
// neu goi canMove(0, 0) tra ve false (gach cu da chat day toi noc) thi bao thua cuoc.
// Su dung de: Kiem tra sau moi lan goi spawnBlock() de quyet dinh dung vong lap game.
    return false;
}

void drawUI() {
// Chuc nang: Su dung gotoXY() de in khung thong tin ben phai bang board, bao gom:
// Diem so hien tai (score), Cap do (level), Hinh anh khoi gach tiep theo (nextB),
// va danh sach cac phim tat huong dan nguoi choi.
// Su dung de: Goi ngay sau ham draw() o cuoi moi vong lap.
}

void pauseGame() {
// Chuc nang: Hien thi thong bao tam dung tren man hinh va dung lenh cho phim
// cho den khi nguoi choi nhan lai phim 'p' thi tiep tuc vong lap.
// Su dung de: Giup nguoi choi tam nghi giua van dau.
}

void showMenu() {
// Chuc nang: Hien thi ten tro choi Tetris, thong tin nhom thuc hien va huong dan co ban,
// cho nguoi choi nhan phim bat ky de bat dau vao van dau.
// Su dung de: Goi dau tien trong ham main() khi vua mo chuong trinh.
}

void showGameOver() {
// Chuc nang: Hien thi thong bao KET THUC TRO CHOI, in ra tong diem cuoi cung
// cua nguoi choi va cho nhan phim truoc khi dong chuong trinh.
// Su dung de: Goi khi ham isGameOver() tra ve gia tri true.
 }