#pragma once

class Vector3 {
   private:
    double m_x;
    double m_y;
    double m_z;

   public:
    Vector3(double x, double y, double z);
    Vector3(Vector3 const &other);

    Vector3& operator=(Vector3 const& other) noexcept;

    Vector3 operator*(double const &k) const;
    Vector3 operator/(double const &k) const;
    Vector3 operator+(double const &k) const;
    Vector3 operator-(double const &k) const;
    Vector3 operator-(void) const;

    Vector3 operator*(Vector3 const &other) const;
    Vector3 operator+(Vector3 const &other) const;
    Vector3 operator-(Vector3 const &other) const;

    bool operator==(Vector3 const &other) const;
    bool operator!=(Vector3 const &other) const;

    double norm(void);
    double angle(Vector3 const &other);
    double dist(Vector3 const &other);

    Vector3 normalize(void);

    double dot(Vector3 const &other);
};
