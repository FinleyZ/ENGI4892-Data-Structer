/*
 * Copyright 2018 Jonathan Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdint>

template<typename T>
class List
{
private:
//    Add whatever you need to add here

    class Node{
    T value_;
    Node* next_;
    Node* prev_;

};

    Node *head_;
    Node *tail_;
    int size_;

public:
    //! An iterator over the list
    class iterator
    {
    public:
        Node* Data;

        iterator(){
            Data = nullptr;
        }

        iterator(Node other){
            Data = other;
        }

        /**
         * The dereference operator.
         *
         * @returns   a reference to the "current" element
         */
        T& operator*() {
            return  Data->value_;
        }


        /**
         * Pre-increment operator (i.e., `++i`).
         *
         * This method increments the iterator and then returns a
         * reference to the newly-incremented iterator.
         *
         * @returns   a reference to this iterator, after incrementing
         */
        iterator& operator++(){
            Data = Data->next_;
            return *this;
        }

        /**
         * Post-increment operator (i.e., `i++`).
         *
         * This method returns a copy of this iterator as it currently
         * is (i.e., pointing where it currently points) and _then_
         * increments itself.
         *
         * @param     ignored   this is only used to distinguish the two
         *                      increment operators (pre- and post-)
         *                      from each other: its value should be
         *                      ignored
         *
         * @returns   an iterator to the previously-current element
         */
        iterator operator++(int ignored){
            iterator it(Data);
//            it = Data;
//            it.Data = new Node;
//            it.Data->value_ = this->Data.value_;
//            it.Data->next_ = this->Data->next_;
//            it.Data->prev_ = this->Data->prev_;
            Data = Data->next_;
            return it;
        }

        //! Is this iterator pointing at the same place as another one?
        bool operator== (const iterator& node) const{
            if(Data == node.Data){
                return true;
            }else{
                return false;
            }
        }

        //! Is this iterator pointing at a different place from another?
        bool operator!= (const iterator& node) const{
            if(Data != node.Data){
                return true;
            }else{
                return false;
            }
        }
    };


    //! Default constructor
    List(){
        head_ = new Node;
        head_-> prev_= nullptr;
        head_->next_ = nullptr;
        head_-> value_ =0;
        tail_ = head_;
        size_ = 0;
    }

    //! Copy constructor
    List(const List& ListCopied){
        head_ = new Node;
        head_-> prev_= nullptr;
        head_-> next_ = nullptr;
        head_-> value_ =0;
        tail_ = head_;
        size_ = 0;
        Node* node = ListCopied.head_->next_;
        while(node!= nullptr) {
            push_back(node->value_);
            node = node->next_;
        }
    }

    //! Move constructor
    List(List&& ListMoved){
        this->head_ = ListMoved.head_;
        this->tail_ = ListMoved.tail_;
        this->size_ =ListMoved.size_;
        ListMoved.head_ = nullptr;
        ListMoved.tail_ = nullptr;
        ListMoved.size_ = 0;
    }

    //! Destructor
    ~List(){
    }

    //! Copy assignment operator
    List& operator= (const List&);

    //! Move assignment operator
    List& operator= (List&&);


    //
    // Accessors:
    //
    //! How many elements are in this list?
    //size_t ?
    size_t size() const{
        return size_;
    }

    //! Is this list empty?
    bool empty() const;

    //! Get an iterator to the beginning of the list
    //------
    iterator begin(){
        iterator beginIt;
        beginIt.Data->prev_=head_->prev_;
        beginIt.Data->next_=head_->next_;
        return beginIt;
    }

    //! Get an iterator just past the end of the list
    //------
    iterator end(){
        iterator endIt;
        endIt.Data->prev_=tail_->prev_;
        endIt.Data->next_=tail_->next_;
        return endIt;
    }


    //
    // Mutators:
    //
    //! Copy an element to the front of the list
    //------
    void push_front(const T& value ){
        insert(begin(),value);
    }

    //! Move an element to the front of the list
    void push_front(T&& value){
        insert(begin(),value);
    }

    //! Copy an element to the back of the list
    void push_back(const T& value){
        insert(end(),value);
    }

    //! Add an element to the back of the list
    void push_back(T&& value){
        insert(begin(),value);
    }

    /**
     * Copy an element into an arbitrary location.
     *
     * This method makes a copy of an element and inserts that copy into a
     * location pointed at by the given iterator. After insertion into a
     * list of n elements, the list should contain n+1 elements (i.e., no
     * existing element should be replaced).
     *
     * @returns   an iterator pointing at the newly-inserted element
     */
    iterator insert(iterator position, const T& value){
        Node* n = new Node;
        n->value_ = value;

        //if the position is end of the list
        if(position != end()){
            Node* temp = position.Data;
            n->next_ = temp;            // change the next_ in n
            n->prev_ = temp->prev_;     //Change the prev_ of n to the prev_ of temp which id prev_ of position.
            if(temp->prev_){            //if the position is not begin of the list.
                temp->prev_->next_ = n;
            }
            temp->prev_ = n;
        }else{
            n->prev_ = tail_;
            n->next_ = nullptr;
            tail_->next_ = n;
            tail_ = n;
        }
        size_++;

        return iterator(n);


    }

    /**
     * Move an element into an arbitrary location.
     *
     * This method inserts an element into a location pointed at by the
     * given iterator, using move semantics to avoid copies. After insertion
     * into a list of n elements, the list should contain n+1 elements
     * (i.e., no existing element should be replaced).
     *
     * @returns   an iterator pointing at the newly-inserted element
     */
    iterator insert(iterator, T&&);

    //! Remove an element from an arbitrary location
    void erase(iterator);

//private:
//    // Add whatever you need to add here
//    T value_;

};
