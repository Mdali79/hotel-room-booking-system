#include<bits/stdc++.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include<unistd.h>
using namespace std;
//unsigned int sleep(unsigned int seconds);
void main_menu(bool*);
vector<pair<int,int>>menu(bool*);
int gradeFourFive(int);

int gradeFourFive(int room,bool emptyRooms[]){
	vector<int>gradeFourFiv;
                        for(int i=40;i<=80;i+=2){
                                gradeFourFiv.push_back(i);
                        }
                        vector<int>::iterator it1=find(gradeFourFiv.begin(),gradeFourFiv.end(),room);
                        if(it1!=gradeFourFiv.end()){
                                system("cls");
                                cout<<"\t\tThis is a grade Four Five  Rooms\n";
                                cout<<"\t\t1.Let Machine Choose you a Grade Four Room\n\t\t2.Stay With Your Decision\n";
                                cout<<"\t\tEnter a option : ";
                                int option;
                                cin>>option;
                                if(option==1){
                                        int size=0+rand()%21;
                                        while(emptyRooms[gradeFourFiv[size]]==true){
                                                size=rand()%21;
                                        }
                                 room=gradeFourFiv[size];
				}
			}
				 return room;
                                      
}

int gradeTwoThree(int room)
{
			int fare=0;
	               	vector<int>gradeTwo(71,1);
                        for(int i=40;i<=70;i+=2){
                                gradeTwo[i]=0;
                        }
                        vector<int>finalGradeTwo;
                        for(int i=30;i<=70;i++){
                                if(gradeTwo[i]){
                                        finalGradeTwo.push_back(i);
                                }
                        }
                        vector<int>::iterator it=find(finalGradeTwo.begin(),finalGradeTwo.end(),room);
                        if(it!=finalGradeTwo.end()){
                                cout<<"\t\tThis is grade Two-Three Room\n";
                                fare=80+rand()%21;
                                cout<<"\t\tYour fare : ";
                                cout<<fare<<'\n';
                   //             rooms.push_back(make_pair(room,fare));
                                Sleep(3000);
                                //continue;
                        }
			return fare;
			
}


vector<pair<int,int>>menu(bool emptyRooms[]){
	vector<pair<int,int>>rooms;
	while(1){
		system("cls");
        cout<<" ";
        //sleep(3);
        cout<<'\t'<<'\t';
        for(int i=0;i<40;i++){
                cout<<"*";
        }
        cout<<'\n';
        cout<<'\t'<<'\t'<<'\t';
        cout<<"Hotel Room Booking System\n";
        cout<<'\t'<<'\t';
        for(int i=0;i<40;i++){
                cout<<"*";
        }
        cout<<'\n';
	//	system("clear");
		cout<<"\t\tRoom No\t\tFare\n";
		vector<pair<int,int>>::iterator it2;
		for(it2=rooms.begin();it2!=rooms.end();it2++){
			cout<<"\t\t"<<it2->first<<"\t\t"<<it2->second<<'\n';
		}
		cout<<"\t\t1.Choose a Room\n\t\t2.Exit\n";
		cout<<"\t\tEnter a option : ";
		int option;
		cin>>option;
		if(option==2)break;
		cout<<"\t\tEnter a Room Number : ";
		int room;
		cin>>room;
		if(emptyRooms[room-1]){
			cout<<"\n\t\tRoom is Booked.Please Choose another one\n";
			Sleep(3000);
			continue;
		}
		else{
			emptyRooms[room-1]=true;
			int fare=gradeTwoThree(room);
			if(fare!=0){
			      rooms.push_back(make_pair(room,fare));
				continue;
			}
			if(room>=40 && room<=80 && room%2==0){
				emptyRooms[room-1]=false;
				room=gradeFourFive(room,emptyRooms);
				cout<<"\t\tRoom No : "<<room<<'\n';
				if(room<61){
					cout<<"\t\tThis is a Single Room\n";
					 fare=100;
					rooms.push_back(make_pair(room,fare));
				}
				else{
					cout<<"\t\tThis is a Double Room\n";
					fare=150;
					rooms.push_back(make_pair(room,fare));
				}
				emptyRooms[room-1]=true;
				Sleep(3000);
				continue;
			}
				
			fare=100;
			emptyRooms[room-1]=true;
			rooms.push_back(make_pair(room,fare));
			cout<<"\t\tThis is a grade one room\n";
			cout<<"\t\tRoom : "<<room<<"\t\tFare :"<<fare<<'\n';
			Sleep(3000);
		}
	}
	return rooms;
}

void main_menu(bool emptyRooms[])
{
	map<string,vector<pair<int,int>>>ReservationByName;
	map<int,vector<pair<int,int>>>ReservationByNumber;
	int id=10000;
	vector<string>names;
	while(1){
		system("cls");
        cout<<" ";
        //sleep(3);
        cout<<'\t'<<'\t';
        for(int i=0;i<40;i++){
                cout<<"*";
        }
        cout<<'\n';
        cout<<'\t'<<'\t'<<'\t';
        cout<<"Hotel Room Booking System\n";
        cout<<'\t'<<'\t';
        for(int i=0;i<40;i++){
                cout<<"*";
        }
        cout<<'\n';
	cout<<"\t\t\t1.Book A Room For Customer\n\t\t\t2.Search Reservation By Number\n\t\t\t3.Search Reservation By Name\n\t\t\t4.Exit Program\n";
	cout<<"\t\t\tEnter Option : ";
	int rev;
	cin>>rev;
	if(rev==4)break;
	if(rev==2){
		 cout<<"\t\t\tEnter Reservation Number : ";
                int s;
                cin>>s;
                map<int,vector<pair<int,int>>>::iterator ft;
                bool flag=true;
                for(ft=ReservationByNumber.begin();ft!=ReservationByNumber.end();ft++){
                        if(ft->first==s){
				int idx=s-10000;
				cout<<"\t\t\tName : "<<names[idx]<<'\n';
                                flag=false;
                                vector<pair<int,int>>::iterator itt;
                                cout<<"\t\t\tRooms\t\tFare\n";
                        for(itt=ft->second.begin();itt!=ft->second.end();itt++){
                                cout<<"\t\t\t"<<itt->first<<"\t\t"<<itt->second<<"\n";
                        }
                        }
                }
                if(flag){
                        cout<<"\t\t\tUser Not Found\n";
			Sleep(3000);
                        continue;
                }
		Sleep(4000);
		continue;
		
	}
	else if(rev==3){
		cout<<"\t\t\tEnter Reservation Name : ";
                string s;
                cin.ignore();
		getline(cin,s);
                map<string,vector<pair<int,int>>>::iterator ft;
                bool flag=true;
                for(ft=ReservationByName.begin();ft!=ReservationByName.end();ft++){
                        if(ft->first==s){
				//int idx=s-10000;
				cout<<"\t\t\tName : "<<s<<'\n';
                                flag=false;
                                vector<pair<int,int>>::iterator itt;
                                cout<<"\t\t\tRooms\t\tFare\n";
                        for(itt=ft->second.begin();itt!=ft->second.end();itt++){
                                cout<<"\t\t\t"<<itt->first<<"\t\t"<<itt->second<<"\n";
                        }
                        }
                }
                if(flag){
                        cout<<"\t\t\tUser Not Found\n";
			Sleep(3000);
                        continue;
                }
		Sleep(4000);
		continue;
	}
		//fflush(stdin);
		string name;
		cout<<"\t\tEnter your name : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\t\tThere are 300 Rooms\n";
	//cout<<"\t\tEnter your Room Number : ";
		//map<string,vector<pair<int,int>>>ReservationByName;
		vector<pair<int,int>>reserve=menu(emptyRooms);
		//ReservationByName.insert({name,reserve});
		ReservationByName[name]=reserve;
		ReservationByNumber.insert({id,reserve});
		cout<<"\n\t\tName: "<<name<<"\n"<<"\t\tReservation Number: "<<id<<"\n";

		//cout<<"\t\t\t"<<name<<"\t\t"<<id<<"\t\t";
		cout<<"\t\tRooms : ";
		vector<pair<int,int>>::iterator it;
		int sum=0;
		for(it=reserve.begin();it!=reserve.end();it++){
			cout<<it->first<<" ";
			sum+=it->second;
		}
		cout<<"\n";
		sum=sum-sum/10;
		cout<<"\t\tFare : "<<sum<<"(With Discount)"<<'\n';
		names.push_back(name);
		id++;
		Sleep(5000);
	}
}

int main()
{
	bool emptyRooms[300]={false};
	main_menu(emptyRooms);
}
