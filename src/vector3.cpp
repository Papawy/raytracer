#include "vector3.h"

#include <cmath>
#include <algorithm>
#include <stdexcept>

Vector3::Vector3(double x, double y, double z)
{
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}

Vector3::Vector3(Vector3 const &other)
{
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_z = other.m_z;
}

Vector3& Vector3::operator=(Vector3 const& other) noexcept
{
    if (this != &other)
    {
        this->m_x = other.m_x;
        this->m_y = other.m_y;
        this->m_z = other.m_z;
    }
    return *this;
}

Vector3 Vector3::operator*(double const &k) const
{
    Vector3 res(this->m_x * k, this->m_y * k, this->m_z * k);
    return res;
}

Vector3 Vector3::operator/(double const &k) const
{
    if (k == 0)
        throw std::domain_error("Division by zero.");
    Vector3 res(this->m_x / k, this->m_y / k, this->m_z / k);
    return res;
}

Vector3 Vector3::operator+(double const &k) const
{
    Vector3 res(this->m_x + k, this->m_y + k, this->m_z + k);
    return res;
}

Vector3 Vector3::operator-(double const &k) const
{
    Vector3 res(this->m_x - k, this->m_y - k, this->m_z - k);
    return res;
}

Vector3 Vector3::operator-(void) const
{
    Vector3 res(-this->m_x, -this->m_y, -this->m_z);
    return res;
}

Vector3 Vector3::operator*(Vector3 const &other) const
{
    Vector3 res(0, 0, 0);
    res.m_x = this->m_y * other.m_z - other.m_y * this->m_z;
    res.m_y = this->m_z * other.m_x - other.m_z * this->m_x;
    res.m_z = this->m_x * other.m_y - other.m_x * this->m_y;
    return res;
}

Vector3 Vector3::operator+(Vector3 const &other) const
{
    Vector3 res(this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z);
    return res;
}

Vector3 Vector3::operator-(Vector3 const &other) const
{
    Vector3 res(this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z);
    return res;
}

bool Vector3::operator==(Vector3 const &other) const
{
    return this->m_x == other.m_x
            && this->m_y == other.m_y
            && this->m_z == other.m_z;
}

bool Vector3::operator!=(Vector3 const &other) const
{
    return !(*(this) == other);
}

double Vector3::norm(void)
{
    return sqrt(this->m_x * this->m_x + this->m_y * this->m_y + this->m_z * this->m_z);
}

double Vector3::angle(Vector3 const &other)
{
    return acos(std::clamp(this->dot(other), -1.0, 1.0));
}

double Vector3::dist(Vector3 const &other)
{
    Vector3 res = *(this) - other;
    return res.norm();
}

Vector3 Vector3::normalize(void)
{
    return *(this) / this->norm();
}

double Vector3::dot(Vector3 const &other)
{
    return this->m_x * other.m_x + this->m_y * other.m_y + this->m_z * other.m_z;
}
