#ifndef HELPER_H
#define HELPER_H

//-----------------------------------------------------------------------------
// Geometry
//-----------------------------------------------------------------------------
class P
{
 public:
 P() :
  x(0),
    y(0) {}

 P(const int x, const int y) :
  x(x),
    y(y) {}

 P(const P& p) :
  x(p.x),
    y(p.y) {}

 P(const int v) :
  x(v),
    y(v) {}

  P& operator=(const P& p)
    {
      x = p.x;
      y = p.y;
      return *this;
    }

  P& operator/=(const int v)
    {
      x /= v;
      y /= v;
      return *this;
    }

  P& operator+=(const P& p)
    {
      x += p.x;
      y += p.y;
      return *this;
    }

  P& operator-=(const P& p)
    {
      x -= p.x;
      y -= p.y;
      return *this;
    }

  P& operator++()
    {
      ++x;
      ++y;
      return *this;
    }

  P& operator--()
    {
      --x;
      --y;
      return *this;
    }

  P operator+(const P& p) const
  {
    return P(x + p.x, y + p.y);
  }

  P operator+(const int  v) const
  {
    return P(x + v, y + v);
  }

  P operator-(const P& p) const
  {
    return P(x - p.x, y - p.y);
  }

  P operator-(const int v) const
  {
    return P(x - v, y - v);
  }

  P operator/(const int  v) const
  {
    return P(x / v, y / v);
  }

  P operator/(const P& p) const
  {
    return P(x / p.x, y / p.y);
  }

  P operator*(const int v) const
    {
      return P(x * v, y * v);
    }

  P operator*(const P& p) const
    {
      return P(x * p.x, y * p.y);
    }

  bool operator==(const P& p) const
  {
    return x == p.x && y == p.y;
  }

  bool operator!=(const P& p) const
  {
    return x != p.x || y != p.y;
  }

  bool operator!=(const int v) const
  {
    return x != v || y != v;
  }

  bool operator>(const P& p) const
  {
    return x > p.x && y > p.y;
  }

  bool operator>(const int v) const
  {
    return x > v && y > v;
  }

  bool operator<(const P& p) const
  {
    return x < p.x && y < p.y;
  }

  bool operator<(const int v) const
  {
    return x < v && y < v;
  }

  bool operator>=(const P& p) const
  {
    return x >= p.x && y >= p.y;
  }

  bool operator>=(const int v) const
  {
    return x >= v && y >= v;
  }

  bool operator<=(const P& p) const
  {
    return x <= p.x && y <= p.y;
  }

  bool operator<=(const int  v) const
  {
    return x <= v && y <= v;
  }

  P signs() const
  {
    return P(x == 0 ? 0 : x > 0 ? 1 : -1,
	     y == 0 ? 0 : y > 0 ? 1 : -1);
  }

  void set(const int x_, const int y_)
  {
    x = x_;
    y = y_;
  }

  void set(const P& p)
  {
    x = p.x;
    y = p.y;
  }

  void swap(P& p)
  {
    P tmp(p);
    p = *this; set(tmp);
  }

  int x, y;
};

#endif
