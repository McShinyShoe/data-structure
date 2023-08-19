namespace shiny {
    template <typename dataType>
    class SinglyLinkedList {
    public:
        struct Node {
            dataType data;
            Node* next;
        };

    private:
        Node* m_head;

    public:
        inline Node* head() {
            return m_head;
        };
        inline const Node* head() const {
            return m_head;
        }
        Node* tail() {
            if(m_head == nullptr)
                return nullptr;
            Node* cursor = m_head;
            while(cursor->next != nullptr)
                cursor = cursor->next;
            return cursor;
        };
        const Node* tail() const {
            if(m_head == nullptr)
                return nullptr;
            Node* cursor = m_head;
            while(cursor->next != nullptr)
                cursor = cursor->next;
            return cursor;
        }
        Node* at(size_t index) {
            if(m_head == nullptr)
                return nullptr;
            Node* cursor = m_head;
            while(index-- && cursor != nullptr)
                cursor = cursor->next;
            return cursor;
        }
        const Node* at(size_t index) const {
            if(m_head == nullptr)
                return nullptr;
            Node* cursor = m_head;
            while(index-- && cursor != nullptr)
                cursor = cursor->next;
            return cursor;
        }
        size_t size() const {
            size_t counter = 0;
            for (Node* cursor = m_head; cursor != nullptr; cursor = cursor->next)
                counter++;
            return counter;
        }
    };
};