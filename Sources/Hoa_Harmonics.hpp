/*
// Copyright (c) 2012-2016 CICM - Universite Paris 8 - Labex Arts H2H.
// Authors :
// 2012: Pierre Guillot, Eliott Paris & Julien Colafrancesco.
// 2012-2015: Pierre Guillot & Eliott Paris.
// 2015: Pierre Guillot & Eliott Paris & Thomas Le Meur (Light version)
// 2016: Pierre Guillot & Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef DEF_HOA_HARMONICS_LIGHT
#define DEF_HOA_HARMONICS_LIGHT

#include "Hoa_Math.hpp"
#include "Hoa_Signal.hpp"

namespace hoa
{
    //! The harmonic class owns basic harmonics ordering informations.
    /** The harmonic allows to retrieves informations about its ACN ordering, the degree and the order.
     */
    template <Dimension D, typename T> class Harmonic
    {
    public:

        //! The harmonic constructor.
        /** The harmonic constructor allocates and initializes the general member values depending on an index.
         @param index    The index must be at least 1.
         */
        Harmonic(const size_t index) hoa_noexcept;

        //! The harmonic destructor.
        /** The harmonic destructor free the memory.
         */
		~Harmonic() hoa_noexcept = 0;

        //! Get the index of the harmonic.
        /** The method returns the index \f$i\f$ of the harmonic.
         @return     The index.
         */
        size_t getIndex() const hoa_noexcept;

        //! Get the degree of the harmonic.
        /** The method returns the degree \f$l\f$ of the harmonic.
         @return     The degree.
         */
        size_t getDegree() const hoa_noexcept;

        //! Get the order of the harmonic.
        /** The method returns the order \f$m\f$ of the harmonic.
         @return     The order.
         */
        long getOrder() const hoa_noexcept;

        //! Get the name of the harmonic.
        /** The method returns the name \f$harmonic_{l,m}\f$ of the harmonic.
         @return     The name.
         */
        std::string getName() const hoa_noexcept;

        //! Get the normalization of the harmonic.
        /** The method returns the normalization of the harmonics.
         @return        The normalization of the harmonics.
         */
        T getNormalization() const hoa_noexcept;

        //! Get the semi-normalization of the harmonic.
        /** The method returns the semi-normalization of the harmonics.
         @return        The semi-normalization of the harmonics.
         */
        T getSemiNormalization() const hoa_noexcept;

        //! Get the index of an harmonic with its degree and its order.
        /** The method returns the index of the harmonic.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The index.
         */
        static size_t getHarmonicIndex(const size_t degree, const long order) hoa_noexcept;

        //! Get the degree of an harmonic with an index.
        /** The method returns the degree of the harmonic.
         @param index  The index of the harmonic.
         @return        The degree.
         */
        static size_t getHarmonicDegree(const size_t index) hoa_noexcept;

        //! Get the order of an harmonic with an index.
        /** The method returns the order of the harmonic.
         @param index  The index of the harmonic.
         @return        The degree.
         */
        static size_t getHarmonicOrder(const size_t index) hoa_noexcept;

        //! Get the number of harmonics for an order of decomposition.
        /** The method returns the number of harmonics for a order of decomposition \f$N\f$.
         @param order   The order of decomposition.
         @return        The number of harmonics.
         */
        static size_t getNumberOfHarmonics(const size_t order) hoa_noexcept;

        //! Get the normalization of an harmonic.
        /** The method returns the normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The normalization of the harmonics.
         */
        static T getNormalization(const size_t degree, const long order) hoa_noexcept;

        //! Get the semi-normalization of an harmonic.
        /** The method returns the semi-normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The semi-normalization of the harmonics.
         */
        static T getSemiNormalization(const size_t degree, const long order) hoa_noexcept;
    };

    //! The harmonic class owns basic harmonics ordering informations.
    /** The harmonic allows to retrieves informations about its ACN ordering, the degree and the order.
     */
    template<typename T> class Harmonic<Hoa2d, T>
    {
    private:
        const size_t m_index;
        const size_t m_degree;
        const long   m_order;
    public:

        //! The harmonic constructor.
        /** The harmonic constructor allocates and initializes the general member values depending on an index.
         @param index    The index must be at least 1.
         */
        inline Harmonic(const size_t index) hoa_noexcept :
        m_index(index), m_degree(getDegree(index)), m_order(getOrder(index)) {}

        //! The harmonic destructor.
        /** The harmonic destructor free the memory.
         */
        inline ~Harmonic() hoa_noexcept hoa_default_f

        //! Get the index of the harmonic.
        /** The method returns the index of the harmonic.
         @return     The index.
         */
        inline size_t getIndex() const hoa_noexcept { return m_index; }

        //! Get the degree of the harmonic.
        /** The method returns the degree of the harmonic.
         @return     The degree.
         */
        inline size_t getDegree() const hoa_noexcept { return m_degree; }

        //! Get the order of the harmonic.
        /** The method returns the order of the harmonic.
         @return     The order.
         */
        inline long getOrder() const hoa_noexcept { return m_order; }

        //! Get the name of the harmonic.
        /** The method returns the name of the harmonic.
         @return     The name.
         */
        inline std::string getName() const hoa_noexcept {
            return "Harmonic " + to_string(m_degree) + " " + to_string(m_order); }

        //! Get the normalization of the harmonic.
        /** The method returns the normalization of the harmonics.
         @return        The normalization of the harmonics.
         */
        inline T getNormalization() const hoa_noexcept { return getNormalization(m_degree, m_order); }

        //! Get the semi-normalization of the harmonic.
        /** The method returns the semi-normalization of the harmonics.
         @return        The semi-normalization of the harmonics.
         */
        inline T getSemiNormalization() const hoa_noexcept { return getSemiNormalization(m_degree, m_order); }

        
        //! Get the degree of an harmonic with an index.
        /** The method returns the degree of the harmonic.
         @param index  The index of the harmonic.
         @return        The degree.
         */
        static inline size_t getDegree(const size_t index) hoa_noexcept {
            return (index + index % 2) / 2ul; }

        //! Get the order of an harmonic with an index.
        /** The method returns the order of the harmonic.
         @param index  The index of the harmonic.
         @return        The order.
         */
        static inline long getOrder(const size_t index) hoa_noexcept {
            return long(long(index + index % 2l) / 2l) * (1l - (long)(index % 2) * 2l); }

        //! Get the index of an harmonic with its degree and its order.
        /** The method returns the index of the harmonic.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The index.
         */
        static inline long getIndex(const size_t degree, const long order) hoa_noexcept {
            return std::abs(order) *  2 - long(order < 0); }

        //! Get the number of harmonics for an order of decomposition.
        /** The method returns the number of harmonics for a order of decomposition.
         @param order   The order of decomposition.
         @return        The number of harmonics.
         */
        static inline size_t getNumberOfHarmonics(const size_t order) hoa_noexcept { return order * 2 + 1; }

        //! Get the normalization of an harmonic.
        /** The method returns the normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The normalization of the harmonics.
         */
        static inline T getNormalization(const size_t degree, const long order) hoa_noexcept { return 1.; }

        //! Get the semi-normalization of an harmonic.
        /** The method returns the semi-normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The semi-normalization of the harmonics.
         */
        static inline T getSemiNormalization(const size_t degree, const long order) hoa_noexcept { return 1.; }
    };

    template <typename T> class Harmonic<Hoa3d, T>
    {
    private:
        const size_t m_index;
        const size_t m_degree;
        const long   m_order;
    public:

        //! The harmonic constructor.
        /** The harmonic constructor allocates and initializes the general member values depending on an index.
         @param index    The index must be at least 1.
         */
        Harmonic(const size_t index) hoa_noexcept :
        m_index(index), m_degree(getDegree(index)), m_order(getOrder(index)) {}

        //! The harmonic destructor.
        /** The harmonic destructor free the memory.
         */
        ~Harmonic() hoa_noexcept hoa_default_f

        //! Get the index of the harmonic.
        /** The method returns the index of the harmonic.
         @return     The index.
         */
        inline size_t getIndex() const hoa_noexcept { return m_index; }

        //! Get the degree of the harmonic.
        /** The method returns the degree of the harmonic.
         @return     The degree.
         */
        inline size_t getDegree() const hoa_noexcept {return m_degree; }

        //! Get the order of the harmonic.
        /** The method returns the order of the harmonic.
         @return     The order.
         */
        inline long getOrder() const hoa_noexcept { return m_order; }

        //! Get the name of the harmonic.
        /** The method returns the name of the harmonic.
         @return     The name.
         */
        inline std::string getName() const hoa_noexcept {
            return "Harmonic " + to_string(m_degree) + " " + to_string(m_order); }

        //! Get the normalization of the harmonic.
        /** The method returns the normalization of the harmonics.
         @return        The normalization of the harmonics.
         */
        inline T getNormalization() const hoa_noexcept { return getNormalization(m_degree, m_order); }

        //! Get the semi-normalization of the harmonic.
        /** The method returns the semi-normalization of the harmonics.
         @return        The semi-normalization of the harmonics.
         */
        inline T getSemiNormalization() const hoa_noexcept { return getSemiNormalization(m_degree, m_order); }
        

        //! Get the degree of an harmonic with an index.
        /** The method returns the degree of the harmonic.
         @param index  The index of the harmonic.
         @return        The degree.
         */
        static inline size_t getDegree(const size_t index) hoa_noexcept {
            return size_t(sqrt(double(index))); }

        //! Get the order of an harmonic with an index.
        /** The method returns the order of the harmonic.
         @param index  The index of the harmonic.
         @return        The order.
         */
        static inline long getOrder(const size_t index) hoa_noexcept {
            return long(index) - (long(sqrt(double(index))) * (long(sqrt(double(index))) + 1)); }

        //! Get the index of an harmonic with its degree and its order.
        /** The method returns the index of the harmonic.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The index.
         */
        static inline size_t getIndex(const size_t degree, const long order) hoa_noexcept {
            return size_t(long(degree * (degree + 1)) + order); }

        //! Get the number of harmonics for an order of decomposition.
        /** The method returns the number of harmonics for a order of decomposition.
         @param order   The order of decomposition.
         @return        The number of harmonics.
         */
        static inline size_t getNumberOfHarmonics(const size_t order) hoa_noexcept  {
            return (order + 1) * (order + 1); }

        //! Get the normalization of an harmonic.
        /** The method returns the normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The normalization of the harmonics.
         */
        static inline T getNormalization(const size_t degree, const long order) hoa_noexcept
        {
            return getSemiNormalization(degree, order) * sqrt(2. * double(degree) + 1.);
        }

        //! Get the semi-normalization of an harmonic.
        /** The method returns the semi-normalization of an harmonics.
         @param degree  The degree of the harmonic.
         @param order   The order of the harmonic.
         @return        The semi-normalization of the harmonics.
         */
        static inline T getSemiNormalization(const size_t degree, const long order) hoa_noexcept
        {
            if(order == 0)
            {
                return T(sqrt(Math<T>::factorial(long(degree) - long(std::abs(order))) / Math<T>::factorial(long(order) + long(std::abs(order))))) * T(sqrt(T(1.) / T(4. * HOA_PI)));
            }
            else
            {
                return T(sqrt(Math<T>::factorial(long(degree) - std::abs(order)) / Math<T>::factorial(long(degree) + std::abs(order))) * sqrt(T(2.) / T(4. * HOA_PI)));
            }
        }
    };
}

#endif


