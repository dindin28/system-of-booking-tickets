#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
int id = 0;
class customer {
public:
int id;
};
class system {

};
class train {
public:
bool place [6];
void clear_places(){
    for (int i = 0; i < 6; i++){
    place[i] = true;
    }
}
void order_places(){
    for (int i = 0; i < 6; i++){
    place[i] = false;
    }
}
void show_places(){
    cout<<"1 - Free, 0 - Booked"<<endl;
    for (int i = 0; i < 6; i++){
    cout << "place #"<< i + 1 << " is " << place[i] << endl;
    }
}
void show_place(int x){
cout << "place #" << x + 1 << " is " << place[x] << endl;
}
};
int main(){
    train first_train;
    first_train.clear_places();
    while (true){
        system("cls");
        cout << "Want to book the place? Press \"B\""<< endl;
        if (GetAsyncKeyState(0x42) == true){
            id++;
            while(true){
                system("cls");
                customer customer;
                cout << "Your id = " << id << endl;
                customer.id = id;
                cout << "To see free places press \"F\""<<endl;
                if (GetAsyncKeyState(0x46) == true){
                    while(true){
                        system("cls");
                        first_train.show_places();
                        cout << "To step back press ESCAPE"<<endl;
                        if (GetAsyncKeyState(VK_ESCAPE) == true){
                            system("cls");
                            break;
                        }
                        Sleep(500);
                    }
                }
                cout << "To book the place press \"B\"" << endl;
                if (GetAsyncKeyState(0x42) == true) {
                    system("cls");
                    first_train.show_places();
                    cout << "Enter the number of place you want to book" << endl;
                    int number_of_place;
                    cin >> number_of_place;
                    number_of_place--;
                    if(first_train.place[number_of_place]){
                        first_train.place[number_of_place]=false;
                        cout << "Place #" << number_of_place + 1 << " booked succesfully" <<endl;
                    } else {
                        cout << "Place #" << number_of_place + 1 << " has been already booked, book another place" << endl;
                    }
                    system("pause");
                }
                cout << "To step back press ESCAPE"<<endl;
                if (GetAsyncKeyState(VK_ESCAPE) == true){
                    system("cls");
                    break;
                }
                Sleep(500);
            }
        }
        cout << "Press ESCAPE to leave" << endl;
        if (GetAsyncKeyState(VK_ESCAPE) == true){
            break;
            }
        Sleep(500);
    }
    return 0;
}
/*    Customer obj;
    obj.id = id;

    cout << "id = " << obj.id << endl;*/
