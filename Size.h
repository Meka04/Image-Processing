//
// Created by dariu on 26/03/2024.
//

#ifndef SIZE_H
#define SIZE_H



class Size {

private:
    unsigned int w, h;
public:
    Size() = default;
    Size(unsigned int w, unsigned int h);
    [[nodiscard]] unsigned int getWidth() const;
    [[nodiscard]] unsigned int getHeight() const;
    void setHeight(unsigned int h);
    void setWidth(unsigned int w);
    bool operator==(const Size& other) const;
    bool operator<=(const Size& other) const;
    bool operator>=(const Size& other) const;
    bool operator<(const Size& other) const;
    bool operator>(const Size& other) const;
};


#endif //SIZE_H
