/*
	file: Vector.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Vector2, Vector3
	declared struct(s): N/A
	declared alias(es): Vector2f, Vector2i, Vector2u, Vector3f, Vector3i, Vector3u

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_VECTOR_HPP
#define VOODOO_VECTOR_HPP

#include <ostream>
#include <limits>

namespace voodoo
{
	#pragma region 2D

	template<typename T> class Vector2
	{
	public:
	
		Vector2<T>() : x(T{}), y(T{}) {};
		Vector2<T>(T x, T y) : x(x), y(y) {};
	
	public:
	
		friend Vector2<T> operator + (const Vector2<T>& a, const Vector2<T>& b) { return Vector2<T>(a.x + b.x, a.y + b.y); }
		friend Vector2<T> operator - (const Vector2<T>& a, const Vector2<T>& b) { return Vector2<T>(a.x - b.x, a.y - b.y); }
	
	public:
	
		friend Vector2<T> operator * (const Vector2<T>& vector2, float scalar) { return Vector2<T>(vector2.x * scalar, vector2.y * scalar); }
		friend Vector2<T> operator / (const Vector2<T>& vector2, float scalar) { return Vector2<T>(vector2.x / scalar, vector2.y / scalar); }
	
	public:
	
		friend Vector2<T> operator * (const Vector2<T>& a, const Vector2<T>& b) { return Vector2<T>(a.x * b.x, a.y * b.y); }
		friend Vector2<T> operator / (const Vector2<T>& a, const Vector2<T>& b) { return Vector2<T>(a.x / b.x, a.y / b.y); }
	
	public:
	
		Vector2<T> operator += (const Vector2<T>& vector2) { return Vector2<T>(this->x += vector2.x, this->y += vector2.y); }
		Vector2<T> operator -= (const Vector2<T>& vector2) { return Vector2<T>(this->x -= vector2.x, this->y -= vector2.y); }
	
	public:
	
		Vector2<T> operator *= (float scalar) { return Vector2<T>(this->x *= scalar, this->y *= scalar); }
		Vector2<T> operator /= (float scalar) { return Vector2<T>(this->x /= scalar, this->y /= scalar); }
	
	public:
	
		Vector2<T> operator *= (const Vector2<T>& vector2) { return Vector2<T>(this->x *= vector2.x, this->y *= vector2.y); }
		Vector2<T> operator /= (const Vector2<T>& vector2) { return Vector2<T>(this->x /= vector2.x, this->y /= vector2.y); }
	
	public:
	
		friend bool operator ==	(const Vector2<T>& a, const Vector2<T>& b) { return ((a.x == b.x) && (a.y == b.y)); }
		friend bool operator !=	(const Vector2<T>& a, const Vector2<T>& b) { return ((a.x != b.x) || (a.y != b.y)); }
	
	public:
	
		friend std::ostream& operator << (std::ostream& os, const Vector2<T>& vector2) { return os << vector2.x << "," << vector2.y; }
	
	public:
	
		T x;
		T y;
	
	public:
	
		static const Vector2<T> Zero;
		static const Vector2<T> Min;
		static const Vector2<T> Max;
	
	};
	
	template <typename T> const Vector2<T> Vector2<T>::Zero	= Vector2<T>(T{}, T{});
	template <typename T> const Vector2<T> Vector2<T>::Min	= Vector2<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::min());
	template <typename T> const Vector2<T> Vector2<T>::Max	= Vector2<T>(std::numeric_limits<T>::max(), std::numeric_limits<T>::max());
	
	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int>;
	using Vector2u = Vector2<unsigned>;
	
	#pragma endregion 2D
	
	
	
	
	
	#pragma region 3D
	
	template<typename T> class Vector3
	{
	public:
	
		Vector3<T>() : x(T{}), y(T{}), z(T{}) {};
		Vector3<T>(T x, T y, T z) : x(x), y(y), z(z) {};
	
	public:
	
		friend Vector3<T> operator + (const Vector3<T>& a, const Vector3<T>& b) { return Vector3<T>(a.x + b.x, a.y + b.y, a.z + b.z); }
		friend Vector3<T> operator - (const Vector3<T>& a, const Vector3<T>& b) { return Vector3<T>(a.x - b.x, a.y - b.y, a.z - b.z); }
	
	public:
	
		friend Vector3<T> operator * (const Vector3<T>& vector3, float scalar) { return Vector3<T>(vector3.x * scalar, vector3.y * scalar, vector3.z * scalar); }
		friend Vector3<T> operator / (const Vector3<T>& vector3, float scalar) { return Vector3<T>(vector3.x / scalar, vector3.y / scalar, vector3.z / scalar); }
	
	public:
	
		friend Vector3<T> operator * (const Vector3<T>& a, const Vector3<T>& b) { return Vector3<T>(a.x * b.x, a.y * b.y, a.z * b.z); }
		friend Vector3<T> operator / (const Vector3<T>& a, const Vector3<T>& b) { return Vector3<T>(a.x / b.x, a.y / b.y, a.z / b.z); }
	
	public:
	
		Vector3<T> operator += (const Vector3<T>& vector3) { return Vector3<T>(this->x += vector3.x, this->y += vector3.y, this->z += vector3.z); }
		Vector3<T> operator -= (const Vector3<T>& vector3) { return Vector3<T>(this->x -= vector3.x, this->y -= vector3.y, this->z -= vector3.z); }
	
	public:
	
		Vector3<T> operator *= (float scalar) { return Vector3<T>(this->x *= scalar, this->y *= scalar, this->z *= scalar); }
		Vector3<T> operator /= (float scalar) { return Vector3<T>(this->x /= scalar, this->y /= scalar, this->z /= scalar); }
	
	public:
	
		Vector3<T> operator *= (const Vector3<T>& vector3) { return Vector3<T>(this->x *= vector3.x, this->y *= vector3.y, this->z *= vector3.z); }
		Vector3<T> operator /= (const Vector3<T>& vector3) { return Vector3<T>(this->x /= vector3.x, this->y /= vector3.y, this->z /= vector3.z); }
	
	public:
	
		friend bool operator ==	(const Vector3<T>& a, const Vector3<T>& b) { return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z)); }
		friend bool operator !=	(const Vector3<T>& a, const Vector3<T>& b) { return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z)); }
	
	public:
	
		friend std::ostream& operator << (std::ostream& os, const Vector3<T>& vector3) { return os << vector3.x << "," << vector3.y << "," << vector3.z; }
	
	public:
	
		T x;
		T y;
		T z;
	
	public:
	
		static const Vector3<T> Zero;
		static const Vector3<T> Min;
		static const Vector3<T> Max;
	
	};
	
	template <typename T> const Vector3<T> Vector3<T>::Zero = Vector3<T>(T{}, T{}, T{});
	template <typename T> const Vector3<T> Vector3<T>::Min	= Vector3<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::min(), std::numeric_limits<T>::min());
	template <typename T> const Vector3<T> Vector3<T>::Max	= Vector3<T>(std::numeric_limits<T>::max(), std::numeric_limits<T>::max(), std::numeric_limits<T>::max());
	
	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<int>;
	using Vector3u = Vector3<unsigned>;
	
	#pragma endregion 3D
}

#endif//VOODOO_VECTOR_HPP