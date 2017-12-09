#ifndef NegativeNum_h
#define NegativeNum_h


class NegativeNum {
protected:
  double value;
public:
  NegativeNum() {
    value = 0;
  }
  NegativeNum(double val)
  {
    value = val;
  }
  double getValue() const
  {
    return value;
  }
};

#endif // NegativeNum_h
