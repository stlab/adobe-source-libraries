/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/**************************************************************************************************/

#ifndef ADOBE_ALGORITHM_UNIQUE_HPP
#define ADOBE_ALGORITHM_UNIQUE_HPP

#include <adobe/config.hpp>

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

#include <algorithm>
#include <functional>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/
/*!
\defgroup unique unique
\ingroup mutating_algorithm

\see
    - STL documentation for \ref stldoc_unique
    - STL documentation for \ref stldoc_unique_copy
*/
/**************************************************************************************************/
/*!
    \ingroup unique

    \brief unique implementation
*/
template <class ForwardRange>
inline typename boost::range_iterator<ForwardRange>::type unique(ForwardRange& range) {
    return std::unique(boost::begin(range), boost::end(range));
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class ForwardIterator, class BinaryPredicate>
inline ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate pred) {
    return std::unique(first, last, std::bind(pred, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class ForwardRange, class BinaryPredicate>
inline typename boost::range_iterator<ForwardRange>::type unique(ForwardRange& range,
                                                                 BinaryPredicate pred) {
    return adobe::unique(boost::begin(range), boost::end(range), pred);
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class InputRange, class OutputIterator>
inline OutputIterator unique_copy(InputRange& range, OutputIterator result) {
    return std::unique_copy(boost::begin(range), boost::end(range), result);
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class InputRange, class OutputIterator>
inline OutputIterator unique_copy(const InputRange& range, OutputIterator result) {
    return std::unique_copy(boost::begin(range), boost::end(range), result);
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class InputIterator, class OutputIterator, class BinaryPredicate>
inline OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result,
                                  BinaryPredicate pred) {
    return std::unique_copy(first, last, result,
                            std::bind(pred, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class InputRange, class OutputIterator, class BinaryPredicate>
inline OutputIterator unique_copy(InputRange& range, OutputIterator result, BinaryPredicate pred) {
    return adobe::unique_copy(boost::begin(range), boost::end(range), result, pred);
}

/*!
    \ingroup unique

    \brief unique implementation
*/
template <class InputRange, class OutputIterator, class BinaryPredicate>
inline OutputIterator unique_copy(const InputRange& range, OutputIterator result,
                                  BinaryPredicate pred) {
    return adobe::unique_copy(boost::begin(range), boost::end(range), result, pred);
}

/**************************************************************************************************/

} // namespace adobe

/**************************************************************************************************/

#endif

/**************************************************************************************************/
