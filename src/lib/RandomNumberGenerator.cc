// Copyright 2011 Jason Marcell

#include <gsl/gsl_cdf.h>

#include "lib/RandomNumberGenerator.h"

namespace jason {

RandomNumberGenerator::RandomNumberGenerator() {
  const gsl_rng_type *T;
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc(T);
}

RandomNumberGenerator::~RandomNumberGenerator() {
  gsl_rng_free(r);
}

double RandomNumberGenerator::SampleGaussian(double sigma) {
  return gsl_ran_gaussian(r, sigma);
}

double RandomNumberGenerator::GaussianPDF(double val) {
  return gsl_ran_ugaussian_pdf(val);
}

double RandomNumberGenerator::GaussianCDF(double val) {
  return gsl_cdf_ugaussian_P(val);
}

double RandomNumberGenerator::SampleUniform(double lower, double upper) {
  return gsl_ran_flat(r, lower, upper);
}
}
