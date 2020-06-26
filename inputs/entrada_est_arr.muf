estructura inicio
    ent edad;
    dreal altura;
fin persona;

def sin imc(ent edad, ent altura) inicio
    ent[2][3] a;
    ent p_imc;

    p_imc := edad + altura;

    persona.altura := 2;
    persona.edad := 2.4f;

    /*a[1][2] := 2;*/
fin 