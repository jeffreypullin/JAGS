#ifndef DSCALED_WISHART_H_
#define DSCALED_WISHART_H_

#include <distribution/ArrayDist.h>

namespace jags {
namespace glm {

/**
 * <pre>
 * x[] ~ dwish(S[], k)
 * </pre>
 * @short Huang and Wand scaled Wishart distribution
 */
class DScaledWishart : public ArrayDist {
public:
  DScaledWishart();

  double logDensity(double const *x, unsigned int length, PDFType type,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper) const;
  void randomSample(double *x, unsigned int length,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper, RNG *rng) const;
  void typicalValue(double *x, unsigned int length,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper) const;
  static void sampleWishart(double *x, unsigned int length,
			    double const *scale, unsigned int nrow,
			    double k, RNG *rng);
  /**
   * Checks that S is a vector and k is a scalar
   */
  bool checkParameterDim(std::vector<std::vector<unsigned int> > const &dims) 
      const;
  /**
   * Checks that S and k are both positive
   */
  bool checkParameterValue(std::vector<double const *> const &parameters,
			   std::vector<std::vector<unsigned int> > const &dims)
      const;
  std::vector<unsigned int> 
      dim(std::vector<std::vector<unsigned int> > const &dims) const;
  void support(double *lower, double *upper, unsigned int length,
	       std::vector<double const *> const &parameters,
	       std::vector<std::vector<unsigned int> > const &dims) const;
  bool isSupportFixed(std::vector<bool> const &fixmask) const;
  unsigned int df(std::vector<std::vector<unsigned int> > const &dims) const;
};

}}

#endif /* DSCALED_WISHART_H_ */
