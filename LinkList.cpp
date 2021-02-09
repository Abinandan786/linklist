// LinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct node {
    int data;
    struct node* next;
};
class linkList {
    node *head;
    int count = 0;
public:
    linkList() { head = NULL; }
    void add_node(int val)
    {    
        count++;
        node* temp = new node;
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
    void printList()
    {
        node* ptr = head;
        if (head == NULL)
        {
            std::cout << "No item in LL";
            return;
        }
        while (ptr!= NULL) {
           std::cout << ptr->data << "->";
             ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    void delete_node(int key)
    {
        node* ptr = head;
        node* pptr = head;
        node* temp = head;
        if (ptr == NULL)
            std::cout << "item has no element" << std::endl;
        else if (ptr->data == key)
        {
            head = ptr->next;
            free(ptr);
        }
        else
        {
            while (ptr->data != key) {
                pptr = ptr;
                ptr = ptr->next;
                
            }
            pptr->next = ptr->next;
            free(ptr);
        }

          
    }
    void delete_pos(int pos)
    {
        node* ptr = head;
        node* pptr = head;
        node* temp = head;
        int i = 1;
        if (pos== 0)
        {
            head = ptr->next;
            free(ptr);
        }
        else if (pos > count)
        {
            std::cout << "Position is greater than node count in list" << std::endl;
        }
        else
        {

            while (i++ < pos) {
                pptr = ptr;
                ptr = ptr->next;
            }
            pptr->next = ptr->next;
            free(ptr);
        }


    }
    void dalete_list()
    {
        node* ptr;
        while (head != NULL)
        {
            ptr = head;
            head = head->next;
            free(ptr);
        }
        head = NULL;
    }
    void delete_dup()
    {
        std::cout << "I am in deete_dup" << std::endl;
        node* current = head;
        while (current->next != NULL)
        {
            std::cout << current->data << "  " << current->next->data << std::endl;
            if (current->data == current->next->data)
            {
                std::cout << current->data << "  " << current->next->data << std::endl;
                node* ptr = current->next;
                current->next = ptr->next;
                free(ptr);
            }
            else {
                current = current->next;
            }
        }

    }
    void reverse()
    {
        node* cur = head;
        node* prev = NULL, * next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

    }
    void moveToFront()
    {
        node* cur = head;
        while (cur->next->next!= NULL)
        {
            std::cout << cur->data << "  " << std::endl;
            cur = cur->next;
        }
        node* ptr = cur->next;
        cur->next = NULL;
        ptr->next = head;
        head = ptr;
       
    }
};

int main()
{
    linkList ll;
    ll.add_node(12);
    ll.add_node(14);
    ll.add_node(16);
    ll.add_node(16);
    ll.add_node(30);
    ll.add_node(30);
    ll.add_node(74);
    ll.add_node(82);
    ll.add_node(82);
    ll.add_node(90);

    ll.printList();
    ll.delete_node(74);
    ll.printList();
    //ll.delete_pos(6);
    ll.printList();
   // ll.dalete_list();
    ll.printList();
    ll.delete_dup();
    ll.printList();
    ll.reverse();
    ll.printList();
    ll.reverse();
    ll.printList();
    ll.moveToFront();
    ll.printList();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
