#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<ctime>
using namespace std;
void Login();
void Register();
int Timey(){//year
	time_t currentime=time(0);
	tm* ltm=localtime(&currentime);
	int year=1900+ltm->tm_year;
    return year;
}
int Timed(){//day
	time_t currentime=time(0);
	tm* ltm=localtime(&currentime);
	int day=ltm->tm_mday;
    return day;
}
int Timem(){//month
	time_t currentime=time(0);
	tm* ltm=localtime(&currentime);
	int month=1+ltm->tm_mon;
    return month;
}
void SetLocation(int x, int y)
{
    COORD Set;
    Set.X = x;
    Set.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Set);
}
void TextLocation(int x, int y, const char *str,int color)
{
    COORD Set;
    Set.X = x;
    Set.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Set);
    cout << str;
}
void loading(){
	int i, k, q, a;
	char c=178;
	SetLocation(60,13);
	cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t  Loading please wait....";
	for(i=1;i<=99;i++){
		SetLocation(75,20);
		a=i+1;
		cout<<a<<"%";
		for(k=0;k<=0.5*i;k++){
			SetLocation(k+50,21);
			cout<<c;
		}
		Sleep(100);
	}
	system("cls ");
	SetLocation(70,12); cout<<"Loading....";
	Sleep(2000);
}
void Welcome()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t                        _                              "<<endl;
	cout<<"\t\t\t\t\t    __      __   __    | |    ___     ___     _ ___ ___     ___ "<<endl;
	cout<<"\t\t\t\t\t    \\ \\ /\\ / /  / _ \\  | |   / __|   / _ \\   | '_  '_  \\   / _ \\"<<endl;

	cout<<"\t\t\t\t\t     \\ v  v /  | ___/  | |  | (__   | (_) |  | | | | | |  | ___/  "<<endl;

	cout<<"\t\t\t\t\t      \\_/\\_/    \\___|  |_|   \\___|   \\___/   |_| |_| |_|   \\___|  "<<endl;
}
class CTextModeGrid
{
	private:
    int m_left, m_top, m_right, m_bottom;
    int m_numRows, m_numCols;
    int m_arrRowHeight[100], m_arrColWidth[100];
    public:
    CTextModeGrid(int l, int t, int r, int b)
    {
        m_left = l;
        m_top = t;
        m_right = r;
        m_bottom = b;
    }
    void SetRows(int rs) { m_numRows = rs; }
    void SetCols(int cs) { m_numCols = cs; }
    void SetRowHeight(int r, int rh) { m_arrRowHeight[r] = rh; }
    void SetColWidth(int c, int cw) { m_arrColWidth[c] = cw; }
    void DrawGrid()
    {
        DrawSquare(m_left, m_top, m_right, m_bottom);
        {
            int pos = m_left;
            for(int i = 0; i < m_numCols; i++)
            {
                pos += m_arrColWidth[i];
                if(pos > m_right)
                    pos = m_right;
                for(int j = m_top; j <= m_bottom; j++)
                {
                    SetLocation(pos, j);
                    cout << (char)(179);
                }
                if(pos == m_left)
                {
                    SetLocation(m_left,m_top);
                    cout << (char) (218);
                    SetLocation(m_left,m_bottom);
                    cout << (char) (192);
                }
                else if(pos == m_right)
                {
                    SetLocation(m_right,m_top);
                    cout << (char) (191);
                    SetLocation(m_right,m_bottom);
                    cout << (char) (217);
                }
                else
                {
                    SetLocation(pos, m_top);
                    cout << (char)(194);
                    SetLocation(pos, m_bottom);
                    cout << (char)(193);
                }
            }
        }
        {
            int pos = m_top;
            for(int i = 0; i < m_numRows; i++)
            {
                pos += m_arrRowHeight[i];
                if(pos > m_bottom)
                    pos = m_bottom;
                for(int j = m_left; j <= m_right; j++)
                {
                    SetLocation(j, pos);
                    cout << (char)(196);
                    int xpos = m_left;
                    for(int k = 0; k < m_numCols; k++)
                    {
                        xpos += m_arrColWidth[k];
                        if( xpos == j)
                        {
                            SetLocation(xpos, pos);
                            if(pos == m_bottom)
                            {
                                cout << (char)(193);
                            }
                            else if(pos == m_top)
                            {
                                cout << (char)(194);
                            }
                            else
                            {
                                cout << (char)(197);
                            }
                        }
                    }
                }
                if(pos == m_top)
                {
                    SetLocation(m_left,m_top);
                    cout << (char) (218);
                    SetLocation(m_right,m_top);
                    cout << (char) (191);
                }
                else if(pos == m_bottom)
                {
                    SetLocation(m_left,m_bottom);
                    cout << (char) (192);
                    SetLocation(m_right,m_bottom);
                    cout << (char) (217);
                }
                else
                {
                    SetLocation(m_left, pos);
                    cout << (char)(195);
                    SetLocation(m_right, pos);
                    cout << (char)(180);
                }
            }
        }

    }
    void DrawSquare(int left, int top, int right, int bottom)
    {
        { // Horz. Lines
            for(int i = left; i <= right; i++)
            {
                SetLocation(i,top);
                cout << (char) (196);
                SetLocation(i,bottom);
                cout << (char) (196);
            }
        }
        { // Vertical Lines
            for(int i = top; i <= bottom; i++)
            {
                SetLocation(left,i);
                cout << (char)(179);
                SetLocation(right,i);
                cout << (char)(179);
            }
        }
        SetLocation(left,top);
        cout << (char) (218);
        SetLocation(right,top);
        cout << (char) (191);
        SetLocation(left,bottom);
        cout << (char) (192);
        SetLocation(right,bottom);
        cout << (char) (217);
    }
};
void SearchDesign()
{
    TextLocation(59, 7, "Search the informations",14);
    TextLocation(44, 10, "Enter the Barcode for Searching : ",2);
}
void header(int row)
{
    int a=2;
    TextLocation(61, 1, "Stock of Products",9);
    TextLocation(33, 4, "BARCODE", 14);
    TextLocation(51, 4, "NAME", 14);
    TextLocation(66, 4, "PRICE($)", 14);
    TextLocation(83, 4, "QUALTITY", 14);
    TextLocation(100, 4, "TOTAL($)", 14);
}
void Login();
void Register();
void MenuFirst();
void MenuFirstControl();
void ViewProductLists();
void MenuProducts();
void Sell_Item();
void MenuSecond();
void MenuSecondControl();
void MenuSell();
class Product
{
    public:
        int pbarcode;
        char  pname[50];
        double pprice, ptotal;
        int pqty;
    public :
        int getBarcode() { return pbarcode; }
        void WriteData()
        {
            TextLocation(68, 5, "Add Product", 15);
            TextLocation(53, 9, "Barcode      : ", 14);
            TextLocation(53, 12, "Product Name : ", 14);
            TextLocation(53, 15, "Qualtity     : ", 14);
            TextLocation(53, 18, "Price        : ", 14);
            SetLocation(68, 9);
            cout << (pbarcode += 1);
            SetLocation(68, 12);
            fflush(stdin);
            cin.getline(pname, 50);
            SetLocation(68, 15);
            cin >> pqty;
            SetLocation(68, 18);
            cin >> pprice;
            ptotal = pqty * pprice;
        }
        void DisplayData(int col)
        {
            SetLocation(36, col);
            cout << pbarcode;
            SetLocation(51, col);
            cout << pname;
            SetLocation(66, col);
            cout << pprice << "$";
            SetLocation(85, col);
            cout << pqty;
            SetLocation(100, col);
            cout << ptotal << "$";
        }
        void Update() {
			fstream file;
			Product Pro;
			file.open("Products.bin", ios::out | ios::in | ios::binary);
			if(file.fail()) cout << "\n\aFile was not found!!" << endl;
			if(file.good() ) {
				int updateByBarcode=this->pbarcode;
				bool isUpdated =  false;
				file.read((char*)&Pro, sizeof(Pro));
				while(file.eof() != true)
                {
					if(updateByBarcode == Pro.pbarcode) {
						int lastRead = file.tellg();
						Pro=*this;
						file.seekp(lastRead - sizeof(Pro));
						file.write((char*)&Pro, sizeof(Pro));
						isUpdated =  true;
					}
					file.read((char*)&Pro, sizeof(Pro));
				}
				if(isUpdated == false) {
					system("cls");
					SetLocation(30,10);
					cout << "\n\n\n\t\t\t\t\t\t\tERROR: Barcode is invalid!!\n\n"<<"\a";
					Sleep(2000);
				}
			}
			file.close();
		}
};
Product Pro;      //Global declaration........
fstream file;
int i, j, n;
int  readlastBarcode() {
	fstream file;
	int lastBarcode;
	file.open("Products.bin", ios::app  | ios::binary);
	if(file.fail()) lastBarcode=0;
	// -> Found
	if(file.good() )
    {
		//file.read((char*)&Pro, sizeof(Pro));
		while(file.eof() != true) {
	         lastBarcode=Pro.pbarcode;
			file.read((char*)&Pro, sizeof(Pro));
		}
	}
    return lastBarcode;
    file.close();
}
void WriteProduct()
{
    file.open("Products.bin", ios::out | ios::app | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    Pro.pbarcode=readlastBarcode();
    Pro.WriteData();
    file.write((char *)&Pro, sizeof(Pro));
    file.close();
}
void ShowProduct()
{
    int col = 6, row = 5, count;
    file.open("Products.bin", ios::in | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    if(file.good())
    {
        while (file.read((char *)&Pro, sizeof(Pro)))
        {
            Pro.DisplayData(col);
            col += 2;
            row += 2;
        }
    count = row + 2;
    header(row);
    file.read((char *)&Pro, sizeof(Pro));
    TextLocation(54, count, "Press any key go to Menu!", 4);
    }
    file.close();
}
void SearchProduct()
{
    file.open("Products.bin", ios::in | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    int SearchBarcode;
    bool Result = false;
    int col = 6, row = 7;
    SearchDesign();
    SetLocation(78, 10);
    cin >> SearchBarcode;
    while (file.read((char *)&Pro, sizeof(Pro)))
    {
        if (SearchBarcode==Pro.getBarcode())
        {
            system("cls");
            Result = true;
            header(row);
            Pro.DisplayData(col);
        }
    }
    if (Result == false)
    {
        system("cls");
        TextLocation(59, 10, "Enter the wrong Record!", 4);
    }
    TextLocation(44, row + 5, "Press [ESC] back to Menu or Any key Search More", 4);
    file.close();
}
void UpdateProduct()
{
    int col = 6, row = 5, count;
    file.open("Products.bin", ios::in | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    while (file.read((char *)&Pro, sizeof(Pro)))
    {
        Pro.DisplayData(col);
        col += 2;
        row += 2;
    }
    count = row + 2;
    file.read((char *)&Pro, sizeof(Pro));
    header(row);
    file.close();
    fstream file1;
    file.open("Products.bin", ios::in | ios::binary);
    file1.open("Change.bin", ios::out | ios::binary);
    int Update_By_Barcode,op;
    bool found = false;
    TextLocation(55, count + 1, "Update the product Instock!", 2);
    TextLocation(55, count + 2, "Enter Barcode for Updating : ", 4);
    SetLocation(84, count + 2);
    cin >> Update_By_Barcode;
    while (file.eof() != true)
    {
        file.read((char *)&Pro, sizeof(Pro));
        if (Update_By_Barcode == Pro.getBarcode())
        {
            system("cls");
            int lastRead = file.tellg();
            found = true;
            do {
					system("cls");
					cout<<__DATE__<<"||"<<__TIME__<<endl;
					SetLocation(62, 5);
					cout <<" EDIT PRODUCT IN STOCK   ";
					SetLocation(64, 7);
					cout<<" 1. Edit itemName   ";
					SetLocation(64,9);
					cout<<" 2. Edit Qty   ";
					SetLocation(64,11);
					cout<<" 3. Edit price ";
					SetLocation(64,13);
					cout<<" 4. Back menu ";
					SetLocation(53,17);
					cout << "Enter Option Above : ";
					cin>>op;
					fflush(stdin);
					cin.clear();
					switch(op) {
						case 1:
							system("cls");
							SetLocation(65, 3);
							cout <<" UPDATE PRODUCT ";
							SetLocation(52, 6);
							cout<<"Enter Name to Update : ";
							fflush(stdin);
							cin.get(Pro.pname, 50);
                            Pro.Update();
                            system("cls");
							cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t<<<<< ";
							cout<<"  Update Successfully   ";
							cout<<">>>>>"<<endl;
							Sleep(2000);
							break;
						case 2:
							system("cls");
							SetLocation(65, 3);
							cout <<" UPDATE PRODUCT ";
							SetLocation(52, 6);
							cout<<"Enter Qty to Update : ";
							fflush(stdin);
							cin>>Pro.pqty;
                            Pro.ptotal = Pro.pqty * Pro.pprice;
                            Pro.Update();
                            system("cls");
							cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t<<<<< ";
							cout<<"  Update Successfully   ";
							cout<<">>>>>"<<endl;
							Sleep(2000);
							break;
						case 3:
							system("cls");
							SetLocation(65, 3);
							cout <<" UPDATE PRODUCT ";
							SetLocation(52, 6);
							cout<<"Enter Price($) to Update : ";
							fflush(stdin);
							cin>>Pro.pprice;
                            Pro.ptotal = Pro.pqty * Pro.pprice;
                            Pro.Update();
                            system("cls");
							cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t<<<<< ";
							cout<<"  Update Successfully   ";
							cout<<">>>>>"<<endl;
							Sleep(2000);
							break;
						case 4:
							system("cls");
							file.close();
							MenuProducts();
							break;
					}
				} while(1);
            file.seekp(lastRead - sizeof(Pro));
            file1.write((char *)&Pro, sizeof(Pro));
        }
        else
        {
            file1.write((char *)&Pro, sizeof(Pro));
        }
    }
    if (found == false)
    {
        TextLocation(58, count + 5, "Update not Sucessful!", 2);
    }
    TextLocation(55, count + 8, "Press [ESC] back to Menu or Any key Update More", 2);
    file.close();
    file1.close();
    remove("Products.bin");
    rename("Change.bin", "Products.bin");
}
void DeleteProduct()
{
    int col = 6, row = 5, count;
    file.open("Products.bin", ios::in | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    while (file.read((char *)&Pro, sizeof(Pro)))
    {
        Pro.DisplayData(col);
        col += 2;
        row += 2;
    }
    count = row + 2;
    file.read((char *)&Pro, sizeof(Pro));
    header(row);
    file.close();
    fstream file1;
    file.open("Products.bin", ios::in | ios::binary);
    file1.open("Delete.bin", ios::out | ios::binary);
    int DeleteBarcode;
    bool found = false;
    TextLocation(55, count + 1, "Delete the product Instock!", 2);
    TextLocation(0, count + 2, "Enter Barcode for Deleting : ", 4);
    SetLocation(29, count + 2);
    fflush(stdin);
    cin >> DeleteBarcode;
    while (file.read((char *)&Pro, sizeof(Pro)))
    {
        if (DeleteBarcode==Pro.getBarcode())
        {
            TextLocation(58, count + 5, "Delete Sucessful!", 2);
            found = true;
        }
        else
        {
            file1.write((char *)&Pro, sizeof(Pro));
        }
    }
    if (found == false)
    {
        TextLocation(58, count + 5, "Delete not Sucessful!", 2);
    }
    TextLocation(55, count + 7, "Press [ESC] back to Menu or Any key Delete More", 2);
    file.close();
    file1.close();
    remove("Products.bin");
    rename("Delete.bin", "Products.bin");
}
char* hidePasswordChar(char* password)
{
	char input;
	int index = 0;
	while(1)
	{
		input = getch();
		if(input == 13)// Key Enter
		{
			break;
		}
		else if(input == 32 || input == 9) //Key space, Key tap
		{
			continue;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				cout << "\b \b";
				index--;
				password[index] = '\0';// empty
			}
		}
		else
		{
			password[index] = input; index++;
		    cout << "*";
		}
	}
	return password;
}
void Register()
	{
		char ReUsername[40],RePassword[40];
		TextLocation(67,7,"SIGN UP FORM",2);
		TextLocation(46,11,"Username/Gmail : ",14);
		TextLocation(46,15,"Password       : ",14);
		ofstream fp("USERNAME&PASSWORD.txt",ios::app);
		SetLocation(65,11);
		fflush(stdin);
		cin.getline(ReUsername,40);
		SetLocation(65,15);
		hidePasswordChar(RePassword);
		fp<<ReUsername<<" "<<RePassword<<endl;
		TextLocation(63,19,"Successful Register!",2);
		fp.close();
	}
void Login()
	{
		char a[30],b[30],Username[30],Password[30];
		int count=0;
		again:
		TextLocation(67,7,"SIGN IN FORM",9);
		TextLocation(46,11,"Username/Gmail : ",14);
		TextLocation(46,15,"Password       : ",14);
		SetLocation(65,11);
		fflush(stdin);
		cin.getline(Username,30);
		SetLocation(65,15);
		hidePasswordChar(Password);
		ifstream Input("USERNAME&PASSWORD.txt");
		while(Input>>a>>b)
		{
			if(strcmp(Username,a)==0 && strcmp(Password,b)==0)
				count=1;
		}
		Input.close();
		if(count==1)
		{
			TextLocation(65,19,"Successful Login ",2);
            Sleep(150);
			for(int i=1;i<=5;i++)
			{
				Sleep(150);
				cout<<".";
			}
            system("cls");
            MenuSecondControl();
        }
		else
		{
			TextLocation(64,19,"Erorr Login ",4);cout<<"\b";
			Sleep(150);
			for(int i=1;i<=5;i++)
			{
				Sleep(150);
				cout<<".";
			}
			TextLocation(60,19,"[BACKSPACE] for Login again",14);
			int ch=getch();
			if(ch==8)
			{
				system("cls");
				goto again;
			}
			else if(ch==27)
			{
				system("cls");
				MenuFirstControl();
			}
			else
			{
				exit(0);
			}
		}
	}
class invoice_Item
{
	public:
		Product Pro;
		int Qty;
		float Amount;
		int Barcode;
	public:
		void Update_QTY(int n) {
			Qty=n;
			Amount=Qty*Pro.pprice;
		}
};
class Invoice {
	public :
		int id;
		int Dated;
		int Datem;
		int Datey;
		char customer[20];
		float total;
		char staff[20];
		invoice_Item in[100];
		int QtyI=0;
	public:
		void Add_invoiceItem(invoice_Item ivt) {
			in[QtyI]=ivt;
			QtyI++;
			total+=ivt.Amount;
		}
		void retotal() {
			total=0;
			for(i=0; i<QtyI; i++)
				total+=in[i].Amount;
		}
		void header(string header) {
			char c=205,b=201,a=200,d=186,e=187,f=188;
			SetLocation(53,2);
			cout<<b;
			for(i=1; i<46; i++)
				cout<<c;
			cout<<e;
			SetLocation(53,3);
			cout<<d<<header<<d;
			SetLocation(53,4);
			cout<<a;
			for( i=1; i<46; i++)
				cout<<c;
			cout<<f;
			cout<<"\n\n";
			cout<<"\n\t\t\t\t                                                                                    ";
			cout << "\n\t\t\t\t    " << left << setw(12) << "NO." << setw(25) << "DESCRIPTION" << setw(10) << "QUANTITY" << right << setw(10) << "PRICE($)" << setw(18) << "AMOUNT($)"<<"     ";
			cout<<"\n\t\t\t\t                                                                                    ";
		}
		void INVOICE() {
			char c=205,b=201,a=200,d=186,e=187,f=188;
            Dated = Timed();
            Datem = Timem();
            Datey = Timey();
			SetLocation(53,2);
			cout<<b;
			for(i=1; i<46; i++)
				cout<<c;
			cout<<e;
			SetLocation(53,3);
			cout<<d<<"                    INVOICE                  "<<d;
			SetLocation(53,4);
			cout<<a;
			for(i=1; i<46; i++)
				cout<<c;
			cout<<f;
			SetLocation(45,7);
			cout<<" Invoice ID : "<<(id +=1);
			SetLocation(86,7);
			cout<<"  Date : "<<Dated<<'/'<<Datem<<"/"<<Datey;
			SetLocation(45,9);
			cout<<" Cashier    : ";
			cin.get(staff,20);
			fflush(stdin);
			SetLocation(86,9);
			cout<<"  Customer  : General customer"<<endl;
			cout<<"\n\n";
			cout<<"\n\t\t\t\t                                                                                       ";
			cout << "\n\t\t\t\t       " << left << setw(12) << "NO." << setw(25) << "DESCRIPTION" << setw(10) << "QUANTITY" << right << setw(10) << "PRICE($)" << setw(18) << "AMOUNT($)"<<"     ";
			cout<<"\n\t\t\t\t                                                                                       ";
			for(i=0; i<QtyI; i++) {
				cout << fixed << setprecision(2);
				cout << "\n\t\t\t\t       " << left << setw(12) <<i+1<< setw(25) << in[i].Pro.pname << setw(20) << in[i].Qty << right << setw(10) << in[i].Pro.pprice << setw(18) << in[i].Amount <<"     "<< endl;
				cout<<"\t\t\t\t---------------------------------------------------------------------------------------";
			}
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tTotal is : "<<total<<" $ ";
		}
		void showIvoice() {
			char c=205,b=201,a=200,d=186,e=187,f=188;
			cout<<"\n\n";
			cout<<"\n\t\t\t\t                                                                                       ";
			cout <<"\n\t\t\t\t       " << left << setw(12) << "NO." << setw(25) << "DESCRIPTION" << setw(10) << "QUANTITY" << right << setw(10) << "PRICE($)" << setw(18) << "AMOUNT($)"<<"     ";
			cout<<"\n\t\t\t\t\t\t                                                                                       ";
			for(i=0; i<QtyI; i++) {
				cout << fixed << setprecision(2);
				cout << "\n\t\t\t\t       " << left << setw(12) <<i+1<< setw(25) << in[i].Pro.pname << setw(10) << in[i].Qty << right << setw(10) << in[i].Pro.pprice << setw(18) << in[i].Amount <<"     "<< endl;
				cout<<"\t\t\t\t---------------------------------------------------------------------------------------";
			}
			cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tTotal : "<<total<<" $ ";
		}
		void showIv() {
			this->header("        Show product to be purchased         ");
			for(i=0; i<QtyI; i++) {
				cout << fixed << setprecision(2);
				cout << "\n\t\t\t\t    " << left << setw(12) <<i+1<< setw(25) << in[i].Pro.pname << setw(20) << in[i].Qty << right << setw(10) << in[i].Pro.pprice << setw(18) << in[i].Amount <<"     "<<endl;
				cout<<"\t\t\t\t------------------------------------------------------------------------------------";
			}
//			Product::Footer();
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTotal  :  "<<total<<" $ ";
		}
		void HeaderHistory() {
			SetLocation(64,4);
			cout << "List History Invoice ";
			SetLocation(48,9);
			cout << "                                                       ";
			SetLocation(48,10);
			cout << "     " << left << setw(12) << "ID" << setw(20) << "CASHIER" << setw(18) << "DATE ";
			SetLocation(48,11);
			cout << "                                                       ";
		}
		void listHistory() {
			cout<<"\n\t\t\t\t\t\t                                                       "<<endl;
			cout << "\t\t\t\t\t\t     " << left << setw(12) <<id<< setw(20) <<staff << Dated <<'/'<<Datem<<'/'<<right<<Datey<<"         "<<endl;
			cout<<"\t\t\t\t\t\t_______________________________________________________";
		}
};
int  ReadlastID() {
	ifstream R;
	int lastID;
	Invoice I;
	R.open("invoiceLists.bin", ios::out | ios::app | ios::binary);
	if(R.fail()) lastID=0;
	if(R.good() ) {
		R.read((char*)&I, sizeof(I));
		while(R.eof() != true) {
			lastID=I.id;
			R.read((char*)&I, sizeof(I));
		}
	}
	R.close();
	return lastID;
}
void ITF(Invoice I) {
	file.open("invoiceLists.bin", ios::out | ios::app | ios::binary);
	I.id=ReadlastID();
	I.INVOICE();
	file.write((char*)&I,sizeof(I));
	file.close();
}
void SearchHistory() {
	Invoice I;
	file.open("invoiceLists.bin", ios::in | ios::binary);
	if(file.fail()) {
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\aFile was not found!!" << endl;
	}
	if(file.good() ) {
		int searchByBarcode;
		bool isSearch =  false;
		int ID;
		cout<<"\n\n\t\t\t\t\tPlease Choose ID invoice to detail : ";
		cin>>ID;
		file.read((char*)&I, sizeof(I));
		while(file.eof() != true) {
			if(ID == I.id) {
				system("cls");
				I.showIvoice();
				isSearch = true;
				break;
			}
			file.read((char*)&I, sizeof(I));
		}
		if(isSearch == false) {
			system("cls");
			cout << "\n\n\n\n\t\t\t\t\t\t\tError: ID is invalid!!\n\n"<<"\a"<<endl;
			Sleep(2000);
			system("cls");
		}
	}// end if good
	file.close();
}
void History() {
	Invoice I;
	file.open("invoiceLists.bin", ios::in | ios::binary);
	if(file.fail()) {
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\aFile was not found!!" << endl;
	}
	if(file.good() ) {
		file.read((char*)&I, sizeof(I));
		I.HeaderHistory();
		while(file.eof() != true) {
			I.listHistory();
			file.read((char*)&I, sizeof(I));
		}
		file.close();
		SearchHistory();
		file.read((char*)&I, sizeof(I));
	}// end if good
	file.close();
}
void Viewsample()
{
	int col = 6, row = 5, count;
    file.open("Products.bin", ios::in | ios::binary);
    if(file.fail())
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
    if(file.good())
    {
        while (file.read((char *)&Pro, sizeof(Pro)))
        {
            Pro.DisplayData(col);
            col += 2;
            row += 2;
        }
    count = row + 2;
    header(row);
    file.read((char *)&Pro, sizeof(Pro));
	file.close();
    }
}
void sell() {
    Invoice I;
back:
	system("cls");
	file.close();
	Viewsample();
	file.open("Products.bin", ios::in | ios::binary);
	if(file.fail()) {
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\aFile was not found!!" << endl;
		Sleep(2000);
	}
	if(file.good() ) {
		int searchByBarcode;
		int QTY;
		bool isSearch =  false;
		cout << "\n\n\t\t\t\t\tEnter barcode you want to sell : ";
		cin>>searchByBarcode;
		fflush(stdin);
		cin.clear();
		file.read((char*)&Pro, sizeof(Pro));
		// Condition
		while(file.eof() != true) {
			if(searchByBarcode == Pro.pbarcode) {
				if(Pro.pqty==0) {
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Out Of Stock !!!"<<"\a"<<endl;
					Sleep(2000);
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t<<< Press [Enter] to Input again and key [ESC] to back Menu >>>>"<<endl;
					char ch=getch();
					if(ch==13)
                    {
                        goto back;
                    }
					if(ch==27) MenuSell();
				}
bQ:
				cout << "\n\n\t\t\t\t   Enter Qty you want to sell     : ";
				cin>>QTY;
				fflush(stdin);
				cin.clear();
				if(QTY>Pro.pqty) {
					system("cls");
					SetLocation(38, 11);
					cout<<"Goods in stock "<<Pro.pqty<<" !!! Please Enter Qty less , if you want to bought"<<"\a"<<endl;
					cout<<"\n\n\n\t\t\t\t\t<<< Press [Enter] to Input Qty again and key [ESC] to back Menu >>>>"<<endl;
					char ch=getch();
					if(ch==13) {
						system("cls");
						file.close();
						Viewsample();
						cout << "\n\n\t\t\tEnter barcode you want to sell :  "<<searchByBarcode;
						goto bQ;
					}
					if(ch==27) MenuSell();
				}
				file.close();
				invoice_Item ivt;
				ivt.Pro=Pro;
				ivt.Update_QTY(QTY);
				I.Add_invoiceItem(ivt);
bs:
				system("cls");
				I.showIvoice();
				char ch;
				cout<<"\n\n\t <<<< Press Key 'O' to Order more |'D' to delete product |'E' to Edit | [Enter] key to submit order|Other key back to menu  >>>>"<<endl;
				ch=getch();
				switch(ch) {
					case 'O':
					case 'o':
						system("cls");
						goto back;
						break;
					case 'D':
					case 'd':
						int index;
						system("cls");
						I.showIv();
						cout<<"\n\n\t\t\t    Input NO. that you want to Delete  : ";
						cin>>index;
						if(index<I.QtyI+1 && index>0 ) {
							for(int i=index-1; i<I.QtyI+1; i++) {
								invoice_Item j;
								j=I.in[i+1];
								I.in[i+1]=I.in[i];
								I.in[i]=j;
							}
							I.QtyI--;
							I.retotal();
						}
						goto bs;
						break;
					case 'E':
					case 'e': {
						system("cls");
						I.showIv();
						cout<<"\n\n\t\t\t    Input NO. that you want to update : ";
						cin>>index;
B:
						if(index<I.QtyI+1 && index>0 ) {
							cout<<"\n\n\t\t\t    Input new QTY  : ";
							cin>>QTY;
							if(QTY>Pro.pqty) {
								system("cls");
								SetLocation(48, 11);
								cout<<" Limited stock Please Enter Qty less "<<QTY<<"\a"<<endl;
								cout<<"\n\n\n\t\t\t\t\t<<< Press Enter to Input Qty again and key [ESC] to back  >>>>"<<endl;
								ch=getch();
								if(ch==13) {
									system("cls");
									I.showIv();
									cout<<"\n\n\t\t\t    Input NO. that you want to update : "<<index;
									goto B;
								} else if(ch==27) goto bs;
							}
							I.in[index-1].Update_QTY(QTY);
							I.retotal();
						}
						goto bs;
						break;
					}
					case 13:
						system("cls");
						ITF(I);
						for(int i=0; i<I.QtyI; i++) {
							I.in[i].Pro.pqty -= I.in[i].Qty;
							I.in[i].Pro.Update();
						}
						cout<<"\n\n\n\t\t\t\t\t\t\t<<< Press other key to back menu >>>"<<endl;
						getch();
						MenuSell();
						break;
					default:
						MenuSell();
				}
				isSearch = true;
				break;
			}
			file.read((char*)&Pro, sizeof(Pro));
		}
		if(isSearch == false) {
			system("cls");
			cout << "\n\n\n\t\t\t\t\t\t\t\tError: Barcode is invalid!!\n\n"<<"\a";
			Sleep(2000);
			system("cls");
			cout<<"\n\n\n\n\n\n\t\t\t\t\t\t<<< Press Enter key to Input again and other key back menu >>>"<<endl;
			char ch=getch();
			if(ch==13) goto back;
			else MenuSell();
		}
		file.close();
		getch();
		goto back;
	}
}
void MenuSell() {
	system("cls");
	cout<<"\n"<<__DATE__<<" || "<<__TIME__<<endl;
	SetLocation(70, 5);
	cout <<"MENU";
	SetLocation(64, 7);
	cout<<" 1. Sell Product       ";
	SetLocation(64,9);
	cout<<" 2. History Invoice   ";
	SetLocation(64,11);
	cout<<" 3. Back to Menu             ";
	int option;
	SetLocation(60,14);
	cout << "Enter Option Above : ";
	cin>>option;
	fflush(stdin);
	cin.clear();
	switch(option) {
		case 1:
			system("cls");
			sell();
			break;
		case 2: {
C2:
			system("cls");
			History();
			cout<<"\n\n\n\t\t\t\t       <<<";
			cout<<" Press Enter key to choose again || Press [ESC] key to back menu ";
			cout<<">>>"<<endl;
			char ch=getch();
			if(ch==13) goto C2;
			if(ch==27)	MenuSell();
			break;
		}
		case 3:
			MenuSecondControl();
			break;
		default:
			cout<<"\n\n\a\t\t\t\t\t\t\t\t\aSorry , wrong choice selected!"<<endl;
			Sleep(2000);
			MenuSell();
	}
}
float AmoutSell() {
	float AmountofSell=0;
	Invoice I;
	file.open("invoiceLists.bin", ios::in | ios::binary);
	if(file.good() ) {
		file.read((char*)&I, sizeof(I));
		while(file.eof() != true) {
			AmountofSell+=I.total;
			file.read((char*)&I, sizeof(I));
		}
	}// end if good
	file.close();
	return AmountofSell;
}
void Report() {
	int total=0;
	double totalAmount=0;
	float totalofsell=AmoutSell();
	file.open("Products.bin", ios::in | ios::binary);
	if(file.fail()) {
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tFile was not found!!" << "\a"<<endl;
	}
	if(file.good() ) {
		file.read((char*)&Pro, sizeof(Pro));
		while(file.eof()!= true) {
			total=total+Pro.pqty;
			totalAmount+=(Pro.pprice*Pro.pqty);
			file.read((char*)&Pro, sizeof(Pro));
		}
		system("cls");
		cout<<"\n  "<<__DATE__<<" || "<<__TIME__<<endl;
        SetLocation(70, 5);
		cout <<"REPORT";
		cout << fixed << setprecision(2);
		SetLocation(55,7);
		cout<<"Total All Product in stock    : "<<total;
		SetLocation(55,9);
		cout<<"Cost of Product in the store  : "<<(totalAmount+totalofsell)<<" $";
		SetLocation(55,11);
		cout<<"Revenue from sales of product : "<<totalofsell<<" $";
	}// end if good
	file.close();
}
void MenuFirst()
{
	TextLocation(60,8,"WELCOME TO COMPUTER SHOP",15);
	TextLocation(53,11,"[1]. Register(If you don't have account.)",14);
	TextLocation(57,15,"[2]. Login(If you have account.)",14);
	TextLocation(68,19,"[3]. EXIT(0)",14);
	TextLocation(5,33,"Create by : Group 5",9);
	TextLocation(58,33,"Institute of Technology of Cambodia",6);
	TextLocation(121,33,"Second Years",10);
	TextLocation(65,22,"Enter Option : ",3);
}
void MenuFirstControl() // for login or register system.
{
	reg:
	int Option;
	do
	{
		system("cls");
		MenuFirst();
		SetLocation(80,22);
	    cin>>Option;
	    switch(Option)
	    {
	    	case 1 :
	    		{
	    			system("cls");
	    			Register();
				}
				break;
			case 2 :
				{
					system("cls");
					Login();
				}
				break;
			case 3 :
				{
                    TextLocation(65,28,"GoodBye! Thank Guy.",3);
					exit(0);
				}
				break;
		}
		getch();
	}while(1);
}
void MenuSecond()  //For management everything.
{
	/*string line(34,char(205));
	SetLocation(55,12);cout<<char(186);
	SetLocation(90,12);cout<<char(186);
	SetLocation(55,11);cout<<char(201)<<line<<char(187);*/
	TextLocation(64,12,"MANAGERMENT SYSTEM",14);
	TextLocation(60,14,"[1]. Management of Product",1);
	TextLocation(60,15,"[2]. Management of Selling",3);
	TextLocation(60,16,"[3]. Back to Menu",6);
	TextLocation(65,19,"ENTER OPTION : ",8);
}
void MenuSecondControl()
{
    int Option;
    do
    {
        system("cls");
        MenuSecond();
        SetLocation(80, 19);
        cin >> Option;
        switch(Option)
        {
            case 1 :
                system("cls");
                MenuProducts();
                break;
            case 2 :
                system("cls");
                MenuSell();
                break;
            case 3 :
                system("cls");
                MenuFirstControl();
                break;
        }
    } while (true);
}
void Admin()
{
    TextLocation(66, 10, "MENU", 9);
    TextLocation(58, 13, "[1]. Add New Product", 14);
    TextLocation(58, 14, "[2]. View Product", 14);
    TextLocation(58, 15, "[3]. Search Product", 14);
    TextLocation(58, 16, "[4]. Update Product", 14);
    TextLocation(58, 17, "[5]. Delete Product", 14);
    TextLocation(58, 18, "[6]. Back to Menu", 14);
    TextLocation(62, 21, "ENTER OPTION : ", 11);
}
void MenuProducts()
{
	int Option, n, i;
    do
    {
        int Choice;
        system("cls");
        Admin();
        SetLocation(77, 21);
        cin >> Choice;
        if(Choice==1)
        {
            do
            {
                system("cls");
                WriteProduct();
                SetLocation(45,23);
				cout << " <<<<< Press [ESC] to back [MENUS] any key [Add] Record again >>>>>";
            } while(getch() != 27);
        }
        else if(Choice==2)
        {
            system("cls");
            ShowProduct();
        }
        else if(Choice==3)
        {
            do
            {
                system("cls");
                SearchProduct();
            } while (getch() != 27);
        }
        else if(Choice==4)
        {
            do
            {
                system("cls");
                UpdateProduct();
            } while (getch() != 27);
        }
        else if(Choice==5)
        {
            do
            {
                system("cls");
                DeleteProduct();
            } while (getch() != 27);
        }
        else if(Choice==6)
        {
            system("cls");
            MenuSecondControl();
        }
        getch();
    }while(1);
}
int main()
{
    system("MODE CON COLS=144 LINES=35");
    cout << fixed << setprecision(2) << endl;
    Welcome();
    loading();
    MenuFirstControl();
    MenuSell();
	getch();
    return 0;
}