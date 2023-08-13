#include <cstring>
#include <cstddef>
#include <initializer_list>
#include <functional>

namespace shiny {
    template <typename dataType, size_t arraySize>
    class Array {
    public:
        class Iterator {
        private:
            dataType* m_ptr;

        public:
            inline dataType& operator*() const {
                return *m_ptr;
            }
            inline dataType* operator->() {
                return m_ptr;
            }
            Iterator& operator++() {
                m_ptr++;
                return *this;
            }
            Iterator operator++(int) {
                Iterator tmp = *this;
                ++m_ptr;
                return tmp;
            }
            Iterator& operator--() {
                m_ptr--;
                return *this;
            }
            Iterator operator--(int) {
                Iterator tmp = *this;
                --m_ptr;
                return tmp;
            }
            Iterator operator+(size_t amount) {
                return Iterator(m_ptr + amount);
            };
            Iterator operator-(size_t amount) {
                return Iterator(m_ptr - amount);
            };
            bool operator==(const Iterator& other) {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const Iterator& other) {
                return m_ptr != other.m_ptr;
            }

            Iterator() {};
            Iterator(dataType* ptr) : m_ptr(ptr) {};
            ~Iterator() {}
        };
        class ConstIterator {
        private:
            const dataType* m_ptr;

        public:
            inline const dataType& operator*() const {
                return *m_ptr;
            }
            inline const dataType* operator->() {
                return m_ptr;
            }
            ConstIterator& operator++() {
                m_ptr++;
                return *this;
            }
            ConstIterator operator++(int) {
                ConstIterator tmp = *this;
                ++m_ptr;
                return tmp;
            }
            ConstIterator& operator--() {
                m_ptr--;
                return *this;
            }
            ConstIterator operator--(int) {
                ConstIterator tmp = *this;
                --m_ptr;
                return tmp;
            }
            ConstIterator operator+(size_t amount) {
                return ConstIterator(m_ptr + amount);
            };
            ConstIterator operator-(size_t amount) {
                return ConstIterator(m_ptr - amount);
            };
            bool operator==(const ConstIterator& other) {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const ConstIterator& other) {
                return m_ptr != other.m_ptr;
            }

            ConstIterator() {};
            ConstIterator(const dataType* ptr) : m_ptr(ptr) {};
            ~ConstIterator() {}
        };
        class ReversedIterator {
        private:
            dataType* m_ptr;

        public:
            inline dataType& operator*() const {
                return *m_ptr;
            }
            inline dataType* operator->() {
                return m_ptr;
            }
            ReversedIterator& operator++() {
                m_ptr--;
                return *this;
            }
            ReversedIterator operator++(int) {
                ReversedIterator tmp = *this;
                --m_ptr;
                return tmp;
            }
            ReversedIterator& operator--() {
                m_ptr++;
                return *this;
            }
            ReversedIterator operator--(int) {
                ReversedIterator tmp = *this;
                ++m_ptr;
                return tmp;
            }
            ReversedIterator operator+(size_t amount) {
                return ReversedIterator(m_ptr - amount);
            };
            ReversedIterator operator-(size_t amount) {
                return ReversedIterator(m_ptr + amount);
            };
            bool operator==(const ReversedIterator& other) {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const ReversedIterator& other) {
                return m_ptr != other.m_ptr;
            }

            ReversedIterator() {};
            ReversedIterator(dataType* ptr) : m_ptr(ptr) {};
            ~ReversedIterator() {}
        };
        class ConstReversedIterator {
        private:
            const dataType* m_ptr;

        public:
            inline const dataType& operator*() const {
                return *m_ptr;
            }
            inline const dataType* operator->() {
                return m_ptr;
            }
            ConstIterator& operator++() {
                m_ptr--;
                return *this;
            }
            ConstReversedIterator operator++(int) {
                ConstReversedIterator tmp = *this;
                --m_ptr;
                return tmp;
            }
            ConstIterator& operator--() {
                m_ptr++;
                return *this;
            }
            ConstReversedIterator operator--(int) {
                ConstReversedIterator tmp = *this;
                ++m_ptr;
                return tmp;
            }
            ConstReversedIterator operator+(size_t amount) {
                return ConstReversedIterator(m_ptr - amount);
            };
            ConstReversedIterator operator-(size_t amount) {
                return ConstReversedIterator(m_ptr + amount);
            };
            bool operator==(const ConstReversedIterator& other) {
                return m_ptr == other.m_ptr;
            };
            bool operator!=(const ConstReversedIterator& other) {
                return m_ptr != other.m_ptr;
            };

            ConstReversedIterator() {};
            ConstReversedIterator(const dataType* ptr) : m_ptr(ptr) {};
            ~ConstReversedIterator() {}
        };

    private:
        dataType m_array[arraySize];

    public:
        inline dataType* data() {
            return m_array;
        };
        inline const dataType* data() const {
            return m_array;
        }
        inline dataType& at(size_t index) {
            return m_array[index];
        };
        inline dataType at(size_t index) const {
            return m_array[index];
        };
        inline size_t size() const {
            return arraySize;
        }
        
        void fill(const dataType& data) {
            for(auto& dat : *this) {
                dat = data;
            }
        }
        size_t find(const dataType& data) const {
            for (size_t i = 0; i < arraySize; i++)
                if(m_array[i] == data)
                    return i;
            return __SIZE_MAX__;
        }
        dataType min() const {
            Iterator temp = begin();
            for (Iterator i = begin(); i != end(); i++)
                if(*temp < *i)
                    temp = i;
            return *temp;
        };
        dataType max() const {
            Iterator temp = begin();
            for (Iterator i = begin(); i != end(); i++)
                if(*temp > *i)
                    temp = i;
            return *temp;
        };
        void swap(size_t indexA, size_t indexB) {
            dataType temp = m_array[indexA];
            m_array[indexA] = m_array[indexB];
            m_array[indexB] = temp;
        }
        template<size_t otherArraySize>
        Array<dataType, arraySize + otherArraySize> concat(const Array<dataType, otherArraySize>& array) const {
            Array<dataType, arraySize + otherArraySize> temp;
            memcpy(temp.data(), m_array, sizeof(dataType) * arraySize);
            memcpy(temp.data() + arraySize, array.data(), sizeof(dataType) * otherArraySize);
            return temp;
        }
        void doToAll(std::function<void(dataType&)> func) {
            for(auto& dat : *this) {
                func(dat);
            }
        }
        void doToAll(std::function<void(dataType)> func) const {
            for(auto& dat : *this) {
                func(dat);
            }
        }

        inline Iterator begin() {
            return Iterator(data());
        }
        inline ConstIterator begin() const {
            return ConstIterator(data());
        }
        inline Iterator end() {
            return Iterator(data() + arraySize);
        }
        inline ConstIterator end() const {
            return ConstIterator(data() + arraySize);
        }

        inline ReversedIterator rbegin() {
            return ReversedIterator(data() + arraySize - 1);
        }
        inline ConstReversedIterator rbegin() const {
            return ConstReversedIterator(data() + arraySize - 1);
        }
        inline ReversedIterator rend() {
            return ReversedIterator(data() - 1);
        }
        inline ConstReversedIterator rend() const {
            return ConstReversedIterator(data() - 1);
        }

        inline ConstReversedIterator crbegin() const {
            return ConstReversedIterator(data() + arraySize - 1);
        }
        inline ConstReversedIterator crend() const {
            return ConstReversedIterator(data() - 1);
        }

        Array() {};
        Array(dataType* array) {
            memcpy(m_array, array, sizeof(dataType) * arraySize);
        }
        Array(const Array& array) {
            memcpy(m_array, array.data(), sizeof(dataType) * arraySize);
        }
        Array(const std::initializer_list<dataType>& list) {
            memcpy(m_array, list.begin(), sizeof(dataType) * (list.size() < arraySize ? list.size() : arraySize));
        }

        Array& operator=(const Array& array) {
            memcpy(m_array, array.data(), sizeof(dataType) * arraySize);
            return *this;
        }
        dataType& operator[](size_t index) {
            return m_array[index];
        }
        template<size_t otherArraySize>
        Array<dataType, arraySize + otherArraySize> operator+(const Array<dataType, otherArraySize>& array) const {
            return concat(array);
        }
    };
};