#ifndef COLA_H
#define COLA_H

struct NodoCola
{
    int valor;
    NodoCola* siguiente;
};


class Cola
{
    private:
        NodoCola* frente;
        NodoCola* fin;

    public:
        Cola();
        ~Cola();

        void encolar(int Valor);
        int desencolar();
        bool estaVacia();
};

#endif