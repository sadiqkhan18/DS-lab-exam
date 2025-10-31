#include <iostream>
using namespace std;

struct patient {
    int patientID;
    patient *previous;
    patient *next;
 
    patient(int pid) {
        patientID = pid;
        previous = next = nullptr;
    }
};

class Erlist {
private:
    patient *head;
    patient *tail;
    int len;

public:
    Erlist() {
        head=tail = nullptr;
        len = 0;
    }

    void insert_First_position(int pid) {
        patient *newNode = new patient(pid);
        if (len == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        len++;
    }

    void insert_End_position(int pid) {
        patient *newNode = new patient(pid);
        if (len == 0) {
            head = tail = newNode;
        } else {
            patient *temp = tail;
            temp->next = newNode;
            newNode->previous = temp;
            tail = newNode;
        }
        len++;
    }

    void insert_Specific_position(int pid) {
        int pos;
        cout<<"Enter a position" << endl;
        cin >> pos;

        if(pos<=1 || head==nullptr) {
            insert_First_position(pid);
            return;
        }
        
        if(pos>len) {
            insert_End_position(pid);
            return;
        }
        
        patient *temp=head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        
        patient *newNode=new patient(pid);
        newNode->previous = temp;
        newNode->next = temp->next;
        
        if(temp->next != nullptr) {
            temp->next->previous = newNode;
        }
        temp->next = newNode;
        len++;
    }

    void Remove() {
        if(head==nullptr) {
            cout <<"List is empty!" << endl;
            return;
        }
        
        patient *temp = head;
        head=head->next;
        if(head != nullptr) {
            head->previous = nullptr;
        } else {
            tail= nullptr;
        }
        delete temp;
        len--;
    }

    void display() {
        patient *temp = head;
        cout << "ER Queue: ";
        while (temp != nullptr) {
            cout << temp->patientID << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Erlist() {
        while(head != nullptr) {
            Remove();
        }
    }
};

int main() {
    Erlist e;
    e.insert_First_position(120); 
    e.display();   
    e.insert_Specific_position(200);
    e.display();    
    e.insert_End_position(150);  
    e.display();
    e.Remove();               
    e.display();
    
    return 0;
}