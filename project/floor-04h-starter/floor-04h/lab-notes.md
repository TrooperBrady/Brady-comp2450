2. For me it crashes. I think the backward walk that reads the bad pointer is p = p->prev

3. Phase 1 (single chain)
    allocations:  1000   deallocations:  1000   leaked:     0   OK
    I don't think this is an error? I think everything went as normal?

    but to answer the question I think delete p; in chain.h line 282 will be the second one to delete the node

4.  

Chain& operator=(const Chain& other) {
    if (this == &other) return *this;
    clear()
    
    for (const Node* p = other.head_; p != nullptr; p = p->next) {
        push_back(p->data);
    }
    return *this;
}





Chain& operator=(const Chain& other) {
    Chain tmp(other);
    swap(tmp);
    return *this;
}

I feel much more comfortable writing the 2nd function. Since it is a lot less code to write compared to the first version

5. The big reason why tail_ pointer can not do pop_back is cause once the tail is deleted the second to last node becomes the new tail. The next pointer will point towards nullprt, which makes it where pop_back won't work

6. The Rule of Thee is if a class needs a custom destructor, it generally also needs a copy constructor and copy-assignment operator. I would use the Rule of Thee for a class that can manage resources automatically. This will make it where it does not need to write its own destructor and copy constructor. The reason chain<t> does not qualify is that is directly manages the dynamically allocated nodes with raw pointers, so it must manually handle the nodes

