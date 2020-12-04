#include <iostream>

using namespace std;
int dotran;
int tocdo;
#define MAX 100
#include"thuvien.h"
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>
#include<MMsystem.h>
#include <sstream>
#include<conio.h>
int score=0;
class Snake;
class Fruit;
bool KiemTraAnQua(Snake snake[] , Fruit fruit);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ve_tuong_tren(){
	int x=10 , y=1;
	while(x<=100){
		gotoXY(x,y);
		cout<<char(177);
		x++;
	}
}

void ve_tuong_duoi(){
	int x=10 , y=26;
	while(x<=100){
		gotoXY(x,y);
		cout<<char(177);
		x++;
	}
}

void ve_tuong_trai(){
	int x=10 , y=1;
	while(y<=26){
		gotoXY(x,y);		
		cout<<char(177);
		y++;
	}
}

void ve_tuong_phai(){
	int x=100,y=1;
	while(y<=26){
		gotoXY(x,y);		
		cout<<char(177);
		y++;
	}
}

void ve_tuong(){
	ve_tuong_phai();
	ve_tuong_trai();
	ve_tuong_tren();
	ve_tuong_duoi();
	
}

class Snake{
	protected:
	int x,  y;
	public:
		Snake();
		~Snake();
		void SetX(int x);
		void SetY(int y);
		int GetX();
		int GetY();		
};

Snake::~Snake(){
}

Snake::Snake(){
	x=50 , y=13;
}

Snake::GetX(){
return x;
}

Snake::GetY(){
	return y;
}

void Snake::SetX(int x){
	this->x=x;
}

void Snake::SetY(int y){
	this->y=y;
}

void CreateSnake(Snake snake[]){
	int x=50 , y=13;
	for(int i=0;i<dotran;i++){
		snake[i].SetX(x);
		snake[i].SetY(y);
		x--;
	}
}

void DrawSnake(Snake snake[]){
	for(int i=0;i<dotran;i++){
		gotoXY(snake[i].GetX() , snake[i].GetY());
		if(i==0) cout<<char(178);
		else cout<<char(176);
	}
}

void DeleteSnake(Snake snake[]){
	for(int i=0;i<dotran;i++){
		gotoXY(snake[i].GetX() , snake[i].GetY());
		 cout<<" ";
	}
}

void Them(Snake snake[],int x , int y ){
	for(int i=dotran;i>0;i--){
		snake[i]=snake[i-1];
	}
	snake[0].SetX(x);
	snake[0].SetY(y);
	dotran++;
}

void Xoa(Snake snake[] , int vitri ){
	for(int i=vitri ; i<dotran;i++){
		snake[i]=snake[i+1];
	}
	dotran--;
}
	
class Fruit : public Snake{
	public:
		Fruit();
		~Fruit();
		void CreateFruit(Snake snake[]);
		bool KiemTraDeQua(Snake snake[]);
};

Fruit::Fruit(){
	x=0;
	y=0;
}

Fruit::~Fruit(){
}

bool Fruit::KiemTraDeQua(Snake snake[]){
	for(int i=0;i<dotran;i++){
		if((x==snake[i].GetX())&&(y==snake[i].GetY())){
			return true; //ran de len qua
		}
	}
	return false;
}

void Fruit::CreateFruit(Snake snake[]){
	do{
	x=rand()%(99-11+1)+11;
	y=rand()%(25-2+1)+2;
    }
	while(KiemTraDeQua(snake)==true);
		int i=rand()%(15-1+1)+1;
		SetColor(i);
		gotoXY(x,y);
		cout<<char(254);
		SetColor(7);	
}

void XuLyDiChuyen(Snake snake[] , int x ,int y , Fruit &fruit){
	Them(snake , x ,y);
	if(KiemTraAnQua(snake , fruit)==false){
		Xoa(snake , dotran-1);
	}
	else{	
		fruit.CreateFruit(snake);
		cout<<char(7);
		score++;
		tocdo-=5;
	}
	DrawSnake(snake);	
}

bool KiemTraChamTuong(Snake snake[]){
	if(snake[0].GetY()==1 && (snake[0].GetX()>=10 && snake[0].GetX()<=100)){
		return true;
	}
	else if(snake[0].GetY()==26 && (snake[0].GetX()>=10 && snake[0].GetX()<=100)){
		return true;
	}
	else if(snake[0].GetX()==100 && (snake[0].GetY()>=1 && snake[0].GetY()<=26)){
		return true;
	}
	else if(snake[0].GetX()==10 && (snake[0].GetY()>=1 && snake[0].GetY()<=26)){
		return true;
	}
	return false;	
}

bool KiemTraChamDuoi(Snake snake[]){
	for(int i=1;i<dotran;i++){
		if((snake[0].GetX()==snake[i].GetX())&&(snake[0].GetY()==snake[i].GetY())){
			return true;
		}
	}
	return false;
}

bool KiemTraThoat(){
	char kitu;
	if(_kbhit()){
		kitu=_getch();
		if(kitu==27) return true;
	}
	return false;
}

bool Logic(Snake snake[]){
	bool kt1 =KiemTraChamTuong(snake);
	bool kt2 =KiemTraChamDuoi(snake);
	if(kt1 == true || kt2 ==true ) return true;
	return false;
}

bool KiemTraDeQua(Snake snake[] , Fruit fruit){
	for(int i=0;i<dotran;i++){
		if((fruit.GetX()==snake[i].GetX())&&fruit.GetY()==snake[i].GetY()){
			return true; //ran de len qua
		}
	}
	return false;
}

bool KiemTraAnQua(Snake snake[] , Fruit fruit){
	if(fruit.GetX()==snake[0].GetX() && fruit.GetY()==snake[0].GetY()){
		return true;
	}
	return false;
}

void logo(){
	cout<<"\n\t\t\t\t\t        @@@@    @@    @   @  @@@@@  ";
	cout<<"\n\t\t\t\t\t       @       @  @   @@ @@  @      ";
	cout<<"\n\t\t\t\t\t       @  @@   @@@@   @ @ @  @@@@@  ";
	cout<<"\n\t\t\t\t\t       @   @  @    @  @   @  @      ";
	cout<<"\n\t\t\t\t\t        @@@   @    @  @   @  @@@@@  ";
	cout<<"\n\n\n";	
	cout<<"\n\t\t\t\t            @@@@  @    @    @@    @   @  @@@@@  ";
	cout<<"\n\t\t\t\t           @.     @@   @   @  @   @  @   @      ";
	cout<<"\n\t\t\t\t             @.   @  @ @   @@@@   @ @    @@@@@  ";
	cout<<"\n\t\t\t\t               @  @   @@  @    @  @  @   @      ";
	cout<<"\n\t\t\t\t           @@@@   @    @  @    @  @   @  @@@@@  ";
	cout<<"\n\n\n";	
}
int main() {
	ofstream infile;
	bool gameover=false;
	string tennguoichoi;
	string nguoichoi;
	logo();
	cout<<"\n\t\t\t\t\t     Nhap ten nguoi choi : ";
    infile.open("file.txt", ios::in | ios::app );
	getline(cin,tennguoichoi);
	infile<<endl<<tennguoichoi;
	infile.close();
	do{
	system("cls");
	SetConSole();
	char game;
	gotoXY(50,0);	
	cout<<"Welcome "<<tennguoichoi<<" enjoy it!!!";
	cout<<"\n1:Play";
	cout<<"\n2.Nguoi choi moi";
	cout<<"\n3:Xem diem";
	cout<<"\n0:Thoat"<<endl;
	cout<<"\nBan hay nhap lua chon: ";
	cin>>game;
    switch(game){
    case '1' : {
   	nguoichoi=tennguoichoi;
    score=0;
    dotran=4;
    tocdo=200;
	gameover=false;
	system("cls");
	gotoXY(50,0);
	cout<<"RAN SAN MOI";
	gotoXY(50,28);
	cout<<"ESC : THOAT.";
	gotoXY(1,0);
	cout<<"TEN NGUOI CHOI : "<<nguoichoi;
	Snake snake[MAX];
	ve_tuong();
	CreateSnake(snake);
	DrawSnake(snake);
	srand(time(NULL));
	Fruit fruit;
	fruit.CreateFruit(snake);
	int x=50 , y=13;
	bool kt=0;
	int check=2;
	bool CursorVisibility;
	while(gameover==false){
			PlaySound(TEXT("C:\\Users\\PC\\Desktop\\GameSnake\\Nhac.wav"),NULL,SND_ASYNC );
		ShowCur(CursorVisibility);
		DeleteSnake(snake);
		if(_kbhit()){
			char kitu;
			kitu=_getch();
			if(kitu==-32){
				kitu=_getch();
				if(kitu==72 && check!=0) check=1; //dilen
				else if (kitu==80 && check !=1) check=0;//xuong
				else if(kitu==77 && check!=3) check=2;//phai
				else if(kitu==75 && check!=2) check=3;//trai			
			}
			else if(kitu==27){
			 kt=1;			 
			}
		}
		//0:di xuong
		//1 : di len
		//2 : phai
		//3 : trai
		//di chuyen
		if(check==0) {
			//xuong
			y++;
		}
		else if(check==1){
			//len
			y--;
		}
		else if(check==2){
			//phai
			x++;
		}
		else if(check==3){
			//trai
			x--;
		}
		if(kt!=1){
		XuLyDiChuyen(snake , x,y , fruit);
		gameover=Logic(snake);
		Sleep(tocdo);
		gotoXY(105,26);
		cout<<"SCORE : "<<score;
		}
		else{
			gameover=kt;
		}
	}}
	system("cls");
	gotoXY(50,1);
	cout<<"Ban Da thua !!"<<endl;	
	system("pause");	
	infile.open("file.txt" , ios::in | ios::app); infile<<"               "<<score; infile.close(); break;
	case '2':{
	system("cls");
	gotoXY(50,0);
	cout<<"Nhap ten nguoi choi : ";
	cin.ignore(1);
	getline(cin,tennguoichoi);
	infile.open("file.txt", ios::in | ios::app );
	infile<<endl<<tennguoichoi;
	infile.close();
	gameover =true;
		break;
	}
    case '3' :{
   	gotoXY(3,7);
   	cout <<"BANG DIEM!";
   	gotoXY(0,8);
   	cout <<"Ten nguoi choi";
   	gotoXY(15,8);
   	cout <<"|| Diem\n";
        ifstream fileinput("file.txt");
    string s;
    while(!fileinput.eof()) {
        char c;
        fileinput.get(c); //read a character
        s += c;       
    }
    cout << s.data() << endl;
	fileinput.close();
	system("pause");
	}
	gameover=true;
	break;	
	case '0' : {		
		exit(1);
	}
	default:{
		system("cls");
		gotoXY(50,0);
		cout<<"Ban da nhap sai!! Bam 1 phim de nhap lai .";
		_getch();
		gameover=true;
		break;
	}		
}
	}while(gameover==true);   
	_getch();	
	return 0;
}
