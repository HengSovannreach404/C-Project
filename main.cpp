#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node{
public:
    string title;
    Node *next;
    Node (string s){
        title = s;
        next = nullptr;
    }
};
class playlist {
private:
    Node *head;
    Node *current;
public:
    playlist(){
        head = nullptr;
        current = nullptr;
    }
    void addSong (string name){
        Node *NewSong = new Node(name);
        if( head == nullptr){
            head = NewSong;
            current = NewSong;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = NewSong;
        }
        cout << "Added :" << name <<endl;
    }
    void display (){
        if( head == nullptr){
            cout << "Playlist is empty." <<endl;
        } else {
            cout << "---- Playlist ----" << endl;
            Node *temp = head;
            while (temp != nullptr){
                if ( temp == current){
                    cout<< ">"<<endl;
                } else {
                    cout << "  " <<endl;
                }
                cout << temp->title << endl;
                temp = temp->next;
            }
        }
    }
};
int main () {
    playlist p1;
    p1.addSong(papaN);
    p1.display();

}