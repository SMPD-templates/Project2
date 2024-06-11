#pragma once
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>


using std::vector;
using std::cout;


template<class u>
class single_linked_list  final {
private:
    //komboi ths listas
    class list_node {
    public:
        u data;
        list_node* next;
    public:
        list_node() :data{ 0 }, next{ nullptr }
        {

        }
        list_node(const u& data1) :data{ data1 }, next{ nullptr }
        {

        }

    };

    size_t size1 = 0;
    list_node* head;
    list_node* ptr;
public:
    //write and iterator (on process)
    using iterator = list_node*;
    using const_iterator = list_node*;
    using const_reverse_iterator = list_node*;
    using reverse_iterator = list_node*;

    //constructors
    single_linked_list() noexcept
    {
        head = nullptr;
        ptr = nullptr;
        size1 = 0;
    }
    single_linked_list(const single_linked_list& a) {

        if (this != &a) {


            list_node* ptr1 = a.head;
            for (int i = 0; i < a.size1; i++) {
                push_back(ptr1->data);
                ptr1 = ptr1->next;

            }
            size1 = a.size1;
        }
        else {

            head = nullptr;
            size1 = 0;
            ptr = nullptr;

        }
        return;

    }
    //iterator when??
    //functions of the class
    template <typename x> void push_back(const x& data1) noexcept {
        if (size1 == 0) {
            size1++;
            head = new(std::nothrow) list_node(data1);
            if (head == nullptr)exit(1);
            ptr = head;


        }
        else {
            size1++;
            ptr->next = new(std::nothrow) list_node(data1);
            if (ptr->next == nullptr)exit(1);
            ptr = ptr->next;
        }
        return;
    }
    void show()const noexcept {
        list_node* ptr1 = head;
        for (size_t i = 0; i < size1; i++) {
            cout << ptr1->data << '\n';
            ptr1 = ptr1->next;
        }

        return;
    }
    void pop_back()noexcept {
        if (size1 > 1) {
            delete ptr;
            size1--;
            ptr = head;
            for (int i = 0; i < size1 - 1; i++) {
                ptr = ptr->next;
            }
            return;

        }
        else if (size1 == 1) {
            size1 = 0;
            ptr = nullptr;
            delete head;
            head = nullptr;
        }

        return;

    }
    bool empty()const noexcept {
        if (head == nullptr)return true;
        else return false;
    }

    void sort()const noexcept {

        if (size1 != 0) {
            for (size_t i = 0; i < size1 - 1; i++) {

                list_node* ptr1 = head;
                for (size_t j = 0; j < size1 - i - 1; j++) {
                    if (ptr1 != nullptr && ptr1->next != nullptr) {
                        if (ptr1->data > ptr1->next->data) {
                            u temp = ptr1->data;
                            ptr1->data = ptr1->next->data;
                            ptr1->next->data = temp;
                        }
                        ptr1 = ptr1->next;
                    }

                }
            }

        }
        return;
    }

    list_node* begin()const noexcept {
        return head;
    }
    list_node* end() const noexcept {
        return (nullptr);
    }
    size_t size() const noexcept {
        return size1;
    }
    void clear() const noexcept {
        this->~single_linked_list();
    }
    void reverse()const  noexcept {
        vector<u>k;
        list_node* ptr1 = head;
        for (size_t i = 0; i < size1; i++) {
            k.push_back(ptr1->data);
            ptr1 = ptr1->next;
        }
        std::reverse(k.begin(), k.end());
        ptr1 = head;
        for (size_t i = 0; i < size1; i++) {
            ptr1->data = k[i];
            ptr1 = ptr1->next;
        }
        return;
    }
    //iterators

    //overloaded operators

    void operator =(const single_linked_list& a) noexcept {

        if (this != &a) {
            if (this->head != nullptr) {

                this->~single_linked_list();


                list_node* ptr1 = a.head;
                for (size_t i = 0; i < a.size1; i++) {
                    push_back(ptr1->data);
                    ptr1 = ptr1->next;
                }
                size1 = a.size1;
            }
            else {


                list_node* ptr1 = a.head;
                for (size_t i = 0; i < a.size1; i++) {
                    push_back(ptr1->data);
                    ptr1 = ptr1->next;
                }
                size1 = a.size1;

            }


        }
        return;
    }





    //destructor
    ~single_linked_list() {
        list_node* ptr1 = head;
        list_node* ptr2 = head;
        for (size_t i = 0; i < size1; i++) {
            ptr2 = ptr2->next;
            delete ptr1;
            ptr1 = ptr2;


        }
        size1 = 0;
        head = nullptr;
        ptr = nullptr;
        return;

    }


};
