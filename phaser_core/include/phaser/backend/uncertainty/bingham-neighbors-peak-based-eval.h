#ifndef PHASER_BACKEND_UNCERTAINTY_BINGHAM_NEIGHBORS_PEAK_BASED_EVAL_H_
#define PHASER_BACKEND_UNCERTAINTY_BINGHAM_NEIGHBORS_PEAK_BASED_EVAL_H_

#include <set>
#include <vector>

#include "phaser/backend/alignment/base-aligner.h"
#include "phaser/backend/uncertainty/z-score-eval.h"
#include "phaser/distribution/bingham.h"

namespace phaser_core {

class BinghamNeighborsPeakBasedEval : public BaseEval {
 public:
  common::BaseDistributionPtr evaluatePeakBasedCorrelation(
      const uint32_t bw, const std::set<uint32_t>& signals,
      const std::vector<double>& normalized_corr) const override;

 private:
  common::Bingham fitRotationalBinghamDistribution(
      const uint32_t bw, const std::set<uint32_t>& signals,
      const std::vector<double>& norm_corr) const;

  void calculateStartEndNeighbor(
      const uint32_t index, const uint32_t n_corr, uint32_t* start,
      uint32_t* end) const;

  void retrievePeakNeighbors(
      const uint32_t bw, const uint32_t start, const uint32_t end,
      const std::vector<double>& norm_corr, Eigen::MatrixXd* samples,
      Eigen::RowVectorXd* weights) const;
};

}  // namespace phaser_core

#endif  // PHASER_BACKEND_UNCERTAINTY_BINGHAM_NEIGHBORS_PEAK_BASED_EVAL_H_
