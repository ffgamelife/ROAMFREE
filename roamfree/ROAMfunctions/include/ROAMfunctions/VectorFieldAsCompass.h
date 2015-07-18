/*
Copyright (c) 2013-2014 Politecnico di Milano.
All rights reserved. This program and the accompanying materials
are made available under the terms of the GNU Lesser Public License v3
which accompanies this distribution, and is available at
https://www.gnu.org/licenses/lgpl.html

Contributors:
    Davide A. Cucci (cucci@elet.polimi.it)
*/



/*
 * VectorFieldAsCompass.h
 *
 *  Created on: Jan 29, 2014
 *      Author: davide
 */

#ifndef VECTORFIELDASCOMPASS_H_
#define VECTORFIELDASCOMPASS_H_

#include <string>
#include <Eigen/Dense>

namespace ROAMfunctions {

class VectorFieldAsCompassM {
private:

public:
  static const bool _usedComponents[];

  static const std::string _paramsNames[];
  static const int _nParams = 1;

  static const unsigned int _ORDER = 0;

  static const unsigned int _ERROR_SIZE = 1;
  static const unsigned int _NOISE_SIZE = 2;
  static const unsigned int _MEASUREMENT_SIZE = 3;

  const std::string* getParamsList() {
    return _paramsNames;
  }
  const int getNParams() {
    return _nParams;
  }

  bool predict(const Eigen::VectorXd &x, double **params,
      const Eigen::VectorXd& z, double dt, Eigen::VectorXd &xhat) {
    return false;
  }

  template<typename T>
  bool error(const Eigen::VectorXd &x, double ** params,
      const Eigen::VectorXd& z, Eigen::MatrixBase<T> const &const_ret) {

    Eigen::Map<Eigen::VectorXd> h(params[0], 3);

    Eigen::MatrixBase<T> & err = const_cast<Eigen::MatrixBase<T>&>(const_ret);

    const static int _OFF = -1;

#   include "generated/VectorFieldAsCompass_Err.cppready"

    return false;
  }

  template<typename T>
  bool errorJacobian(const Eigen::VectorXd &x, double ** params,
      const Eigen::VectorXd& z, int wrt,
      Eigen::MatrixBase<T> const &const_ret) {

    Eigen::Map<Eigen::VectorXd> h(params[0], 3);

    Eigen::MatrixBase<T> & J = const_cast<Eigen::MatrixBase<T>&>(const_ret);

    const static int _OFF = -1;

    switch (wrt) {
    case -2: // jacobian wrt to q
    {
#     include "generated/VectorFieldAsCompass_JErrQ.cppready"
      return true;
      break;
    }
    case 0: // jacobian wrt to noises
    {
#     include "generated/VectorFieldAsCompass_JErrNoises.cppready"
      return true;
      break;
    }
    }

    assert(false);
    return false;
  }
};

} /* namespace ROAMfunctions */
#endif /* VECTORFIELDASCOMPASS_H_ */