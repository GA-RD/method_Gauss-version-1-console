#pragma once

class equation {
public:
    float x, y, z, sum;

    equation(float x, float y, float z,float sum);
    equation();
    equation operator - (const equation & other);
    equation & operator = (const equation& other);
    bool operator == (const equation& other);
    bool operator != (const equation& other);

};

equation unite(const equation& one, const equation& second = equation(0, 0, 0, 0));

equation calculation(const equation& one, equation& second, equation& third);
