class Measure {
    private:
        int little;
        int lot; // 7 littles
        int heap; // 23 lots
        void reflow(){};
        int allLittles(){}
    public:
        Measure() {};
        Measure(int littles) {};
        Measure(int littles, int lots, int heaps) {};

        int getLittle() {};
        int getLot() {};
        int getHeap() {};

        Measure operator+(Measure& right);
        Measure operator-(Measure right);
        Measure operator*(Measure right);
        Measure operator/(Measure right);
        bool operator==(Measure right);
        void operator!(); // operator -> string
};