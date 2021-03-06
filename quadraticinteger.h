/*
Copyright (C) 2014, 2015, 2016
Rafael Guglielmetti, rafael.guglielmetti@unifr.ch
*/

/*
This file is part of AlVin.

CoxIter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

CoxIter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AlVin. If not, see <http://www.gnu.org/licenses/>.
*/

/*!
 * \file quadraticinteger.h
 * \author Rafael Guglielmetti
 * 
 * \class QuadraticInteger
 * \brief Quadratic integers
*/

#ifndef QUADRATICINTEGER_SMALL_H
#define QUADRATICINTEGER_SMALL_H

#include "algebraicinteger.h"

#include <cmath>
#include <vector>
#include <map>
#include <array>
#include <string>

using namespace std;

class QuadraticInteger : public AlgebraicInteger
{
	public:
		long int a; ///< First component of the quadratic integer (in the usual Z-basis)
		long int b; ///< Second component of the quadratic integer (in the usual Z-basis)
		static int d; ///< We work in Q[ sqrt d ]
		static bool bIsOneMod4; ///< True if d is 1 mod 4, false otherwise
		static int iDiscriminant; ///< Discriminant of the quadratic field
		
		static map< unsigned int, vector< unsigned int > > iPellMinimalSolution; ///< Solutions for the Pell equations (used to compute the decompositions of rational prime numbers)
		static map< unsigned int, vector< long int > > iFundamentalUnits; ///< Fundamental units
		
	public:
		QuadraticInteger();
		QuadraticInteger( const int& iVal );
		QuadraticInteger( const QuadraticInteger& qi );
		QuadraticInteger( int a, int b );
		virtual ~QuadraticInteger();
		
		AlgebraicInteger* copy() const;
		AlgebraicInteger* aiCopyToInteger( const int& n ) const;
		virtual void set( const int& n );
		virtual void set( AlgebraicInteger* ai );
		
		virtual void removeSquareFactors();
		
		virtual bool bIsInvertible() const;
		virtual bool bIsSquareOfIvertible() const;
		
		virtual void gcd( const AlgebraicInteger* ai );
		virtual bool bIsDivisbleBy( const AlgebraicInteger* ) const;
		virtual void divideBy( const AlgebraicInteger *ai );
		virtual bool divideByIfDivisible( const AlgebraicInteger* ai );
		virtual void multiplyBy( const int& n );
		virtual void multiplyBy( const AlgebraicInteger *ai );
		virtual void add( const AlgebraicInteger *ai );
		virtual void substract( const AlgebraicInteger *ai );
		virtual void opp();
		
		virtual bool bIsLessThan( const int& n ) const;
		virtual bool bIsLessThan( const long int& n ) const;
		virtual bool bIsLessThan( const AlgebraicInteger& ai ) const;
		virtual bool bIsLessOEThan( const AlgebraicInteger& ai ) const;
		virtual bool bIsGreaterThan( const int& n ) const;
		virtual bool bIsGreaterThan( const long int& n ) const;
		virtual bool bIsGreaterOEThan( const int& n ) const;
		virtual bool bIsEqualTo( const AlgebraicInteger& ai ) const;
		virtual bool bIsEqualTo( const int& n ) const;
		
		ostream& print( ostream& ) const;
		virtual string to_string( const string& strFormat = "generic", const bool& bProtect = false ) const;
		virtual double to_double() const;
		virtual string get_classname() const;
		
		long int floor() const;
		
	public:
		static bool bIsDAdmissible( const unsigned int& d );
		static void set_d( const unsigned int& d );
		static vector< QuadraticInteger > qiFactorsRationalPrime( const unsigned int& iPrime, bool bWithMultiplicities = false );
		static array< long int, 2 > iPellEquation( const unsigned int& iPrime );
		static long int iSQRT_quotient( const QuadraticInteger &qiNum, const QuadraticInteger &qiDen );
		static long int iSQRTsup_quotient( const QuadraticInteger &qiNum, const QuadraticInteger &qiDen );
		
		void conjugate();
		long int iNorm() const;
		long int iTrace() const;
		
		int iValuation( const QuadraticInteger& qi );

		vector< QuadraticInteger > qiPrimeFactors() const;
		map< QuadraticInteger, unsigned int > qiPrimeDecomposition() const;
		
		bool bIsAssociateTo( QuadraticInteger qi2 );
		
		// --------------------------------------------
		// Operators
		QuadraticInteger& operator=( const QuadraticInteger& );
		QuadraticInteger& operator/=( QuadraticInteger const &qi );
		QuadraticInteger& operator*=( QuadraticInteger const &qi );
		
		QuadraticInteger operator+( const QuadraticInteger& ) const;
		QuadraticInteger operator*( const QuadraticInteger& ) const;
		QuadraticInteger operator-( const QuadraticInteger& ) const;
		QuadraticInteger operator-() const;
		
		bool operator>(const QuadraticInteger& );
};

bool operator<( const QuadraticInteger& qi1, const QuadraticInteger& qi2 );

#endif // QUADRATICINTEGER_H
