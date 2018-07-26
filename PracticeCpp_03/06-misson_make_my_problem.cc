/*
    Copyright 2018 Moreal
*/

// 다중상속에서 유명한 다이아 패턴에서의 문제점을 아시나요?
// 아신다면 그것을 해결할 방법을 구현해보세요!!
// Programmer class <= JavaProgrammer class, C Programmer class <= GodProgrammer class

class Programmer {
 protected:
    bool isCoding;
};

class JavaProgrammer : virtual public Programmer {};

class CProgrammer : virtual public Programmer {};

class GodProgrammer : public JavaProgrammer, public CProgrammer {
    void coding() { isCoding = true; }
};