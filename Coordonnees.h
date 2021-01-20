#ifndef __AG_COORD__
#define __AG_COORD__

#include<cmath>
#include<ostream>

/*
@brief --copyright Augustin Giraudier 2020--*/
namespace AG
{
	template<typename T>
	class CCoordonnee
	{
	protected:
		/*------------------------------------------------Données membres------------------------------------------------*/
		/*
		@brief Coordonnée x*/
		T m_X;
		/*
		@brief Coordonnée y*/
		T m_Y;

	public:
		/*------------------------------------------------Constructs------------------------------------------------*/
		/*
		@return Coordonnée initialisée à 0*/
		CCoordonnee();
		/*
		@return Coordonnée construite avec x et y*/
		CCoordonnee(T x, T y);
		/*
		@return Nouvel objet Coordonnée copié
		@param const CCoordonnee<T>& coord : objet à copier*/
		CCoordonnee(const CCoordonnee<T>& coord);

		/*------------------------------------------------getters / setters------------------------------------------------*/
		/*
		@return coordonnée x*/
		T getX()const { return m_X; }
		/*
		@return coordonnée y*/
		T getY()const { return m_Y; }
		/*
		@brief modifie la valeur en x
		@param x : nouvelle coordonnée x*/
		void setX(T x) { m_X = x; }
		/*
		@brief modifie la valeur en y
		@param y : nouvelle coordonnée y*/
		void setY(T y) { m_Y = y; }

		/*------------------------------------------------méthodes------------------------------------------------*/
		/*
		@brief divise chaque coordonnée par la norme du vecteur considéré par ces coordonnées*/
		virtual void normer();
		/*
		@return norme du vecteur considéré par les coordonnées*/
		virtual T norme() const = 0;
	};

	template<typename T>
	class CCoordonnee2D
		: public AG::CCoordonnee<T>
	{
	public:
		/*------------------------------------------------Constructs------------------------------------------------*/
		/*
		@return Coordonnée initialisée à 0*/
		CCoordonnee2D();
		/*
		@return Coordonnée construite avec x et y*/
		CCoordonnee2D(T x, T y);
		/*
		@return Nouvel objet Coordonnée copié
		@param const CCoordonnee<T>& coord : objet à copier*/
		CCoordonnee2D(const CCoordonnee2D<T>& coord);

		/*------------------------------------------------méthodes------------------------------------------------*/
		/*
		@return norme du vecteur considéré par les coordonnées*/
		T norme() const override;
	};

	template<typename T>
	class CCoordonnee3D
		: public AG::CCoordonnee<T>
	{
	private:
		/*------------------------------------------------Données membres------------------------------------------------*/
		/*
		@brief Coordonnée z*/
		T m_Z;
	public:
		/*------------------------------------------------Constructs------------------------------------------------*/
		/*
		@return Coordonnée initialisée à 0*/
		CCoordonnee3D();
		/*
		@return Coordonnée construite avec x et y*/
		CCoordonnee3D(T x, T y, T z);
		/*
		@return Nouvel objet Coordonnée copié
		@param const CCoordonnee<T>& coord : objet à copier*/
		CCoordonnee3D(const CCoordonnee3D<T>& coord);

		/*------------------------------------------------getters / setters------------------------------------------------*/
		/*
		@return Coordonnée z*/
		T getZ()const { return m_Z; }
		/*
		@brief modifie la valeur de la coordonnée z
		@param z : nouvelle valeur pour z*/
		void setZ(T z) { m_Z = z; }

		/*------------------------------------------------méthodes------------------------------------------------*/
		/*
		@return norme du vecteur considéré par les coordonnées*/
		T norme() const override;
		/*
		@brief divise chaque coordonnée par la norme du vecteur considéré par ces coordonnées*/
		void normer() override;
	};

	/*------------------------------------------------opérateurs------------------------------------------------*/

	//coordonnee2D :
	template<typename T>
	std::ostream& operator<<(std::ostream& out, CCoordonnee2D<T> Co)
	{
		out << "(" << Co.getX() << " ; " << Co.getY() << ")";
		return out;
	}
	template<typename T>
	T operator*(CCoordonnee2D<T>& CoA, CCoordonnee2D<T>& CoB)
	{
		return CoA.getX()* CoB.getX() + CoA.getY() * CoB.getY();
	}
	template<typename T>
	CCoordonnee2D<T> operator+(CCoordonnee2D<T>& CoA, CCoordonnee2D<T>& CoB)
	{
		return CCoordonnee2D<T> (CoA.getX() + CoB.getX(), CoA.getY() + CoB.getY());
	}
	template<typename T>
	CCoordonnee2D<T> operator-(CCoordonnee2D<T>& CoA, CCoordonnee2D<T>& CoB)
	{
		return CCoordonnee2D<T>(CoA.getX() - CoB.getX(), CoA.getY() - CoB.getY());
	}

	//coordonnees3D :
	template<typename T>
	std::ostream& operator<<(std::ostream& out, CCoordonnee3D<T> Co)
	{
		out << "(" << Co.getX() << " ; " << Co.getY() << " ; " << Co.getZ() << ")";
		return out;
	}
	template<typename T>
	T operator*(CCoordonnee3D<T>& CoA, CCoordonnee3D<T>& CoB)
	{
		return CoA.getX() * CoB.getX() + CoA.getY() * CoB.getY() + CoA.getZ() * CoB.getZ();
	}
	template<typename T>
	CCoordonnee3D<T> operator+(CCoordonnee3D<T>& CoA, CCoordonnee3D<T>& CoB)
	{
		return CCoordonnee3D<T>(CoA.getX() + CoB.getX(), CoA.getY() + CoB.getY(),CoA.getZ() + CoB.getZ());
	}
	template<typename T>
	CCoordonnee3D<T> operator-(CCoordonnee3D<T>& CoA, CCoordonnee3D<T>& CoB)
	{
		return CCoordonnee3D<T>(CoA.getX() - CoB.getX(), CoA.getY() - CoB.getY(), CoA.getZ() - CoB.getZ());
	}

	/*------------------------------------------------Constructs / Méthodes------------------------------------------------*/

	template<typename T>
	inline AG::CCoordonnee<T>::CCoordonnee()
		:m_X(0)
		,m_Y(0)
	{
	}
	template<typename T>
	CCoordonnee<T>::CCoordonnee(T x, T y)
		:m_X(x)
		, m_Y(y)
	{
	}
	template<typename T>
	CCoordonnee<T>::CCoordonnee(const CCoordonnee<T>& coord)
	{
		m_X = coord.getX();
		m_Y = coord.getY();
	}
	template<typename T>
	T CCoordonnee<T>::norme() const
	{
		return sqrt((m_X * m_X) + (m_Y * m_Y));
	}
	template<typename T>
	void CCoordonnee<T>::normer()
	{
		setX(getX() / norme());
		setY(getY() / norme());
	}
	template<typename T>
	inline AG::CCoordonnee2D<T>::CCoordonnee2D()
		:AG::CCoordonnee<T>()
	{
	}
	template<typename T>
	inline AG::CCoordonnee2D<T>::CCoordonnee2D(T x, T y)
		:CCoordonnee<T>(x,y)
	{
	}
	template<typename T>
	inline AG::CCoordonnee2D<T>::CCoordonnee2D(const CCoordonnee2D<T>& coord)
		:CCoordonnee<T>(coord)
	{
	}
	template<typename T>
	inline T AG::CCoordonnee2D<T>::norme() const
	{
		return CCoordonnee<T>::norme();
	}
	template<typename T>
	inline AG::CCoordonnee3D<T>::CCoordonnee3D()
		:CCoordonnee<T>()
		,m_Z(0)
	{
	}
	template<typename T>
	inline AG::CCoordonnee3D<T>::CCoordonnee3D(T x, T y, T z)
		:CCoordonnee<T>(x,y)
		,m_Z(z)
	{
	}
	template<typename T>
	inline CCoordonnee3D<T>::CCoordonnee3D(const CCoordonnee3D<T>& coord)
	{
		this->m_X = coord.getX();
		this->m_Y = coord.getY();
		this->m_Z = coord.getZ();
	}
	template<typename T>
	inline T CCoordonnee3D<T>::norme() const
	{
		return sqrt((this->m_X * this->m_X)+(this->m_Y * this->m_Y)+(this->m_Z * this->m_Z));
	}
	template<typename T>
	inline void CCoordonnee3D<T>::normer()
	{
		this->setX(this->getX() / norme());
		this->setY(this->getY() / norme());
		this->setZ(this->getZ() / norme());
	}
}
#endif