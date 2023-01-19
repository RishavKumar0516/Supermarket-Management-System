#include<bits/stdc++.h>
using namespace std;

class shopping{
	int pcode;   //product code
	float price;
	float dis;
	string pname;  //product name;
public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem(); 
	void list();
	void recipt();
};

void shopping :: menu(){

	m:
	int choice;
	string email;
	string passward;

	cout<<"\t\t\t______________________________________________________\n";
	cout<<"\t\t\t                                                      \n";
	cout<<"\t\t\t                 Supermarket Main Menu                \n";
	cout<<"\t\t\t                                                      \n";
	cout<<"\t\t\t______________________________________________________\n";
	cout<<"\t\t\t                                                      \n";
	cout<<"\t\t\t|    1)  administrator    |\n";
	cout<<"\t\t\t|                         |\n";
	cout<<"\t\t\t|    2)  Buyer            |\n";
	cout<<"\t\t\t|                         |\n";
	cout<<"\t\t\t|    3)  Exit             |\n";
    cout<<"\t\t\t|                         |\n";
	cout<<"\t\t\t   Please select!...             ";
	cin>>choice;

	switch(choice){
	case 1:
		 {
		   cout<<"\t\t\t    Please Login       \n";
		   cout<<"\t\t\t    Enter Email       :  ";
		   cin>>email;
		   cout<<"\t\t\t    passward          :  ";
           cin>>passward;
   		   if(email=="robby@gmail.com" && passward=="robby@123"){
   		   	administrator();
   		   }
   		   else{
   		   	cout<<"\t\t\t     Invalid email/passward\n";
   		   }
		   break;
	    }

	case 2:
		{
           buyer();
		}

	case 3:
		{
			exit(0);
		}

	default :
		{
            cout<<"\t\t\t\nPlease select from the given options\n";
	    }
	}

	goto m;


}

void shopping :: administrator(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\t    Administrator menu";
	cout<<"\n\t\t\t|______1)  Add the product____________|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|______2)  Modify the product_________|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|______3)  Delete the product_________|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|______4)  Back to main menu__________|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\n\t  Please enter the choice                ";
	cin>>choice;

	switch(choice){
	   case 1:
	   	{
	   		add();
	   		break;
	   	}
	   case 2:
	   	{
	   		edit();
	   		break;
	   	}
	   case 3:
	   	{
	   		rem();
	   		break;
	   	}
	   case 4:
	   	{
	   		menu();
	   		break;
	   	}
	   default :
	   	cout<<"\n\t\t\tInvalid choice";
	}
	goto m;

}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\t\t\t    1)  Buyer          \n";
	cout<<"\t\t\t                       \n";
	cout<<"\t\t\t    2)  Buy product    \n";
	cout<<"\t\t\t                       \n";
	cout<<"\t\t\t    3)  Go back        \n";
	cout<<"\t\t\t    Enter your choice  :     ";

	cin>>choice;

	switch(choice){
        case 1:
          {
          	 recipt();
          	 break;
          }
        case 2:
          {
          	 menu();
          }
        default :
        	cout<<"Invalid choice";
	}

	goto m;  // it will help to again jump to the top
}

void shopping ::  add(){
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;

	cout<<"\n\n\t\t\t  Add new product";
	cout<<"\n\n\t  product code of the product     ";
	cin>>pcode;
	cout<<"\n\n\t  Name of the product             ";
	cin>>pname;
	cout<<"\n\n\t Price of the product             ";
	cin>>price;
	cout<<"\n\n\t Discount on product              ";
	cin>>dis;

	data.open("database.txt", ios::in);

	if(! data){
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;

		while(! data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}

	if(token == 1)
		goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	cout<<"\n\n\t\t   Record inserted! ";
}

void shopping :: edit(){
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;

	cout<<"\n\t\t\t  Modify the record";
	cout<<"\n\t\t\t Product code :             ";
	cin>>pkey;

	data.open("database.txt", ios::in);
	if(! data)
	{
		cout<<"\n\nFile doesn't exists!";
	}
	else{

		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(! data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\t  Product new code :      ";
				cin>>c;
				cout<<"\n\t\t\t Name of the product :    ";
				cin>>n;
				cout<<"\n\t\t\t Discount :               ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t Record edited ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
}


void shopping :: rem(){

	fstream data, data1;
	int pkey;
	int token = 0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t product code";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\t\t\tFile doesn't exist!    \n";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(! data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t product deleted successfully\n";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list(){
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n|_______________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|_______________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::recipt(){

	fstream data;
	int arrc[100];
	int arrq[100];
	string choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total = 0;
	cout<<"\n\n\t\t\t\t  RECIEPT";
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}

	else
	{
		data.close();

		list();
		cout<<"\n_____________________________________________________\n";
		cout<<"\n|                                                    \n";
		cout<<"\n                    Please place the order           \n";
		cout<<"\n|                                                    \n";
		cout<<"\n_____________________________________________________\n";

		do{
			m:
			cout<<"\n\nEnter Product Code  :";
			cin>>arrc[c];
			cout<<"\n\n Enter the product quantity :";
			cin>>arrq[c];
			for(int i = 0; i < c; i++){
				  if(arrc[c]==arrc[i])
				  {
				  	cout<<"\n\n Duplicate product code. Please try again! ";
				  	goto m;
				  }
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press yes else no\t";
			cin>>choice;
		}while(choice=="yes");

		cout<<"\n\n\t\t____________________RECEIPT_______________________\n";
		cout<<"\nProduct No\t Product Name\t Product Quantity\t price\t Amount\t Amount with discount\n";


		for(int i = 0; i < c; i++){
			data.open("database.txt", ios::in);
			data>>pcode>>pname>>price>>dis;
			while(! data.eof()){
				if(pcode==arrc[i])
				{
					amount = price*arrq[i];
					dis = amount - (amount*dis/100);
					total = total+dis;
					cout<<"\n  "<<pcode<<"\t\t   "<<pname<<"\t\t"<<arrq[i]<<"\t\t  "<<price<<"\t  "<<amount<<"\t     "<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
	}
	cout<<"\n\n___________________________________________________________________________________________";
	cout<<"\n Total Amount  :  "<<total<<"\n";
}

int main(){
	
	shopping s;
	s.menu();
	cout<<"Rishav Ecart logistics"<<endl;
}