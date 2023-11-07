template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato()
    {
        return dato;
    }
    void setDato(T d)
    {
        dato = d;
    }
    Nodo<T> *getSiguiente()
    {
        return siguiente;
    }
    // El this funciona para decir "Aca voy a reemplazara por un puntero a mi mismo"
    void setSiguiente(Nodo<T> *s)
    {
        this->siguiente = s;
    }
};
