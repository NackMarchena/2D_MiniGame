#pragma once
#include "PersonajeBase.h"


enum PoseHabitante
{
    HCaminarArriba = 3,
    HCaminarAbajo = 0,
    HCaminarIzquierda = 1,
    HCaminarDerecha = 2
};



class PHabitante :
    public PersonajeBase
{

protected:


    PoseHabitante posehabitante;
    int direccionHabitante;
    int saludHabitante;
    bool pedirAyuda;
    
public:


    PHabitante(Bitmap^ img, int _alto, int _ancho);

    void Mover(Graphics^ g);

    void Dibujar(Graphics^ g, Bitmap^ img);

    void SubeSalud();

    bool VerificaSalud();
};

class GenHabitante
{
private:
    vector<PHabitante*> habitantes;
public:

    ~GenHabitante();
   // int EliminaAliado(Rectangle r);

    int Size();
    PHabitante* Get(int pos);
    void Agregar(PHabitante* habitante);
    void Vaciar();
    void Mover(Graphics^ g);
    void Dibujar(Graphics^ g, Bitmap^ img);
    int AsisteAliado(Rectangle agente);
};