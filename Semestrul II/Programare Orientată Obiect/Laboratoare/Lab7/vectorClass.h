#pragma once
#ifndef _VECTORT_H_
#define _VECTORT_H_
template <typename ElemType>
class vectorIterator;

template <typename ElemType>
class vectorClass
{
public:
    vectorClass(int s=5) ;
    vectorClass(const vectorClass& ot);
    ~vectorClass();
    vectorClass& operator=(const vectorClass& ot) noexcept;
    vectorClass(vectorClass&& ot);
    vectorClass& operator=(vectorClass&& ot)noexcept;
    void push_back(const ElemType&);
    ElemType& at(int i) const noexcept;
    void set(int i, ElemType value);
    void erase(int erasevalue);
    int size() const noexcept { return nrElem; };

    friend class vectorIterator<ElemType>;
    vectorIterator<ElemType> begin() noexcept;
    vectorIterator<ElemType> end() noexcept;

private:
    int cap; 
    int nrElem;
    ElemType* elems;

    void ensureCapacity();
};

//Constructorul 
template <typename ElemType >
vectorClass<ElemType>::vectorClass(int s) 
{
    cap = s;
    nrElem = 0;  
    elems = new ElemType[cap];
}

//Constructorul de copiere
template<typename ElemType>
vectorClass<ElemType>::vectorClass(const vectorClass<ElemType>& ot) {
    elems = new ElemType[ot.cap];
    for (int i = 0; i < ot.nrElem; i++) {
        elems[i] = ot.elems[i];  
    }
    nrElem = ot.nrElem;
    cap = ot.cap;
}

template<typename ElemType>
vectorClass<ElemType>& vectorClass<ElemType>::operator=(const vectorClass<ElemType>& ot) noexcept{
    if (this == &ot) {
        return *this;
    }
    delete[] elems;
    elems = new ElemType[ot.cap];
    for (int i = 0; i < ot.nrElem; i++) {
        elems[i] = ot.elems[i]; 
    }
    nrElem = ot.nrElem;
    cap = ot.cap;
    return *this;
}

//Destructorul
template<typename ElemType>
vectorClass<ElemType>::~vectorClass() {
    delete[] elems;
}

template<typename ElemType>
vectorClass<ElemType>::vectorClass(vectorClass&& ot) {
    elems = ot.elems;
    nrElem = ot.nrElem;
    cap = ot.cap;

    ot.elems = nullptr;
    ot.nrElem = 0;
    ot.cap = 0;
}

template<typename ElemType>
vectorClass<ElemType>& vectorClass<ElemType>::operator=(vectorClass<ElemType>&& ot) noexcept{
    if (this == &ot) {
        return *this;}
    delete[] elems;
    elems = ot.elems;
    nrElem = ot.nrElem;
    cap = ot.cap;

    ot.elems = nullptr;
    ot.nrElem = 0;
    ot.cap = 0;
    return *this;
}



//Functia de adaugare la final a unui element
//Parametrii: item - const ElemType&, elementul ce urmeaza a fi adaugat
//Post: lista elems primeste pe pozitia nrElem++ noul element, astfel creste si nrElem
template <typename ElemType>
void vectorClass<ElemType>::push_back(const ElemType& item)
{
    ensureCapacity();
    elems[nrElem++] = item;
}

//Functia de realocare de spatiu
//Post: Daca nu mai este spatiu disponibil, se dubleaza capacitatea si se realocheaza elementele intr-o lista noua
template<typename ElemType>
void vectorClass<ElemType>::ensureCapacity() {
    if (nrElem < cap) {
        return; //mai avem loc
    }
    cap *= 2;
    ElemType* aux = new ElemType[cap];
    for (int i = 0; i < nrElem; i++) {
        aux[i] = elems[i];
    }
    delete[] elems;
    elems = aux;
    /*if (nrElem >= cap)
    {
        cap = cap * 2;
        ElemType* aux = new ElemType[cap];
        for (int i = 0;i < nrElem;i++)
            if (elems != nullptr)
                aux[i] = elems[i];
        if (elems != nullptr)
            delete[] elems;
        elems = aux;
    }*/
}

//Functia de returnare a unui element din lista
//Parametrii: i - int, reprezinta pozitia
//Post: Returneaza elementul de pe pozita i
template <typename ElemType>
ElemType& vectorClass<ElemType>::at(int i) const noexcept
{
    return elems[i];
}

//Functia de modificare a unui element din lista
//Parametrii: i - int, reprezinta pozitia
//            value - ElemType, noul element
//Post: Elementul de pe pozita i va fi inlocui cu value
template <typename ElemType>
void vectorClass<ElemType>::set(int i, ElemType value)
{
    elems[i] = value;
}

//Functia de stergere a unui element din lista
//Parametrii: erasevalue - int, reprezinta pozitia elementului ce trebuie sters
//Post: elementul de pe pozitia erasevalue va fi sters, iar nrElem va scade cu 1
template <typename ElemType>
void vectorClass<ElemType>::erase(int erasevalue)
{
    int sem = 0;

    for (int i = 0;i < nrElem;i++)
    {
        if (i == erasevalue)
            sem = 1;
        if (sem == 1)
            elems[i] = elems[i + 1];
    }
    if (sem == 1)
    {
        nrElem--;
    }

}

//Functia de returnare a unui iterator de la inceputul listei
//Post: Se returneaza un iterator ce reprezinta elemetul de pe pozitia 0
template<typename ElemType>
vectorIterator<ElemType> vectorClass<ElemType>::begin() noexcept
{
    return vectorIterator<ElemType>(*this);
}

//Functia de returnare a unui iterator de la sfarsitul listei
//Post: Se returneaza un iterator ce reprezinta elemetul de pe pozitia nrElem
template<typename ElemType>
vectorIterator<ElemType> vectorClass<ElemType>::end() noexcept
{
    return vectorIterator<ElemType>(*this, nrElem);
}


template<typename ElemType>
class vectorIterator {
private:
    const vectorClass<ElemType>& v;
    int poz = 0;
public:
    vectorIterator(const vectorClass<ElemType>& v) noexcept;
    vectorIterator(const vectorClass<ElemType>& v, int poz)noexcept;
    bool valid()const;
    ElemType& element() const noexcept;
    void next() noexcept;
    ElemType& operator*() noexcept;
    vectorIterator& operator++() noexcept;
    bool operator==(const vectorIterator& ot)noexcept;
    bool operator!=(const vectorIterator& ot)noexcept;
};


template<typename ElemType>
vectorIterator<ElemType>::vectorIterator(const vectorClass<ElemType>& v) noexcept :v{ v } {}

template<typename ElemType>
vectorIterator<ElemType>::vectorIterator(const vectorClass<ElemType>& v, int poz)noexcept : v{ v }, poz{ poz } {}

//Functia de validare a unui iterator
//Post: returneaza true daca poz < nrElem, false altfel
template<typename ElemType>
bool vectorIterator<ElemType>::valid()const {
    return poz < v.nrElem;
}

//Functia de returnare a unui element
//Post: returneaza un element de la poz
template<typename ElemType>
ElemType& vectorIterator<ElemType>::element() const noexcept{
    return v.elems[poz];
}

//Functia de crestere a iteratorului cu 1
//Post: poz creste cu 1
template<typename ElemType>
void vectorIterator<ElemType>::next() noexcept{
    poz++;
}

template<typename ElemType>
ElemType& vectorIterator<ElemType>::operator*() noexcept{
    return element();
}

template<typename ElemType>
vectorIterator<ElemType>& vectorIterator<ElemType>::operator++() noexcept{
    next();
    return *this;
}

template<typename ElemType>
bool vectorIterator<ElemType>::operator==(const vectorIterator<ElemType>& ot) noexcept {
    return poz == ot.poz;
}

template<typename ElemType>
bool vectorIterator<ElemType>::operator!=(const vectorIterator<ElemType>& ot)noexcept {
    return !(*this == ot);
}

#endif

