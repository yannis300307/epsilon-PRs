#ifndef POINCARE_COSINE_H
#define POINCARE_COSINE_H

#include <poincare/approximation_helper.h>
#include <poincare/expression.h>
#include <poincare/trigonometry.h>

namespace Poincare {

class CosineNode final : public ExpressionNode {
 public:
  constexpr static AliasesList k_functionName = "cos";

  // TreeNode
  size_t size() const override { return sizeof(CosineNode); }
  int numberOfChildren() const override;
#if POINCARE_TREE_LOG
  void logNodeName(std::ostream& stream) const override { stream << "Cosine"; }
#endif

  // Properties
  Type type() const override { return Type::Cosine; }

  template <typename T>
  static std::complex<T> computeOnComplex(
      const std::complex<T> c, Preferences::ComplexFormat complexFormat,
      Preferences::AngleUnit angleUnit = Preferences::AngleUnit::Radian);

 private:
  // Layout
  Layout createLayout(Preferences::PrintFloatMode floatDisplayMode,
                      int numberOfSignificantDigits,
                      Context* context) const override;
  size_t serialize(char* buffer, size_t bufferSize,
                   Preferences::PrintFloatMode floatDisplayMode,
                   int numberOfSignificantDigits) const override;
  // Simplication
  Expression shallowReduce(const ReductionContext& reductionContext) override;
  LayoutShape leftLayoutShape() const override {
    return LayoutShape::MoreLetters;
  };
  LayoutShape rightLayoutShape() const override {
    return LayoutShape::BoundaryPunctuation;
  }

  // Derivation
  bool derivate(const ReductionContext& reductionContext, Symbol symbol,
                Expression symbolValue) override;
  Expression unaryFunctionDifferential(
      const ReductionContext& reductionContext) override;

  // Evaluation
  Evaluation<float> approximate(
      SinglePrecision p,
      const ApproximationContext& approximationContext) const override {
    return ApproximationHelper::MapOneChild<float>(this, approximationContext,
                                                   computeOnComplex<float>);
  }
  Evaluation<double> approximate(
      DoublePrecision p,
      const ApproximationContext& approximationContext) const override {
    return ApproximationHelper::MapOneChild<double>(this, approximationContext,
                                                    computeOnComplex<double>);
  }
};

class Cosine final : public ExpressionOneChild<Cosine, CosineNode> {
 public:
  using ExpressionBuilder::ExpressionBuilder;

  bool derivate(const ReductionContext& reductionContext, Symbol symbol,
                Expression symbolValue);
  Expression unaryFunctionDifferential(
      const ReductionContext& reductionContext);
};

}  // namespace Poincare

#endif
