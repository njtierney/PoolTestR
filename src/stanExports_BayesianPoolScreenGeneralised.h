// Generated by rstantools.  Do not edit by hand.

/*
    PoolTestR is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PoolTestR is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PoolTestR.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_BayesianPoolScreenGeneralised_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_BayesianPoolScreenGeneralised");
    reader.add_event(37, 35, "end", "model_BayesianPoolScreenGeneralised");
    return reader;
}
#include <stan_meta_header.hpp>
class model_BayesianPoolScreenGeneralised : public prob_grad {
private:
        int N;
        std::vector<int> PoolSizes;
        int G;
        std::vector<std::vector<int> > PosPools;
        std::vector<std::vector<int> > NegPools;
        int A;
        matrix_d MM;
        std::vector<std::vector<int> > TotPools;
public:
    model_BayesianPoolScreenGeneralised(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_BayesianPoolScreenGeneralised(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_BayesianPoolScreenGeneralised_namespace::model_BayesianPoolScreenGeneralised";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 3;
            validate_non_negative_index("PoolSizes", "N", N);
            context__.validate_dims("data initialization", "PoolSizes", "int", context__.to_vec(N));
            PoolSizes = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("PoolSizes");
            pos__ = 0;
            size_t PoolSizes_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < PoolSizes_k_0_max__; ++k_0__) {
                PoolSizes[k_0__] = vals_i__[pos__++];
            }
            size_t PoolSizes_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < PoolSizes_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "PoolSizes[i_0__]", PoolSizes[i_0__], 1);
            }
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "G", "int", context__.to_vec());
            G = int(0);
            vals_i__ = context__.vals_i("G");
            pos__ = 0;
            G = vals_i__[pos__++];
            check_greater_or_equal(function__, "G", G, 1);
            current_statement_begin__ = 5;
            validate_non_negative_index("PosPools", "N", N);
            validate_non_negative_index("PosPools", "G", G);
            context__.validate_dims("data initialization", "PosPools", "int", context__.to_vec(N,G));
            PosPools = std::vector<std::vector<int> >(N, std::vector<int>(G, int(0)));
            vals_i__ = context__.vals_i("PosPools");
            pos__ = 0;
            size_t PosPools_k_0_max__ = N;
            size_t PosPools_k_1_max__ = G;
            for (size_t k_1__ = 0; k_1__ < PosPools_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < PosPools_k_0_max__; ++k_0__) {
                    PosPools[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t PosPools_i_0_max__ = N;
            size_t PosPools_i_1_max__ = G;
            for (size_t i_0__ = 0; i_0__ < PosPools_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < PosPools_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "PosPools[i_0__][i_1__]", PosPools[i_0__][i_1__], 0);
                }
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("NegPools", "N", N);
            validate_non_negative_index("NegPools", "G", G);
            context__.validate_dims("data initialization", "NegPools", "int", context__.to_vec(N,G));
            NegPools = std::vector<std::vector<int> >(N, std::vector<int>(G, int(0)));
            vals_i__ = context__.vals_i("NegPools");
            pos__ = 0;
            size_t NegPools_k_0_max__ = N;
            size_t NegPools_k_1_max__ = G;
            for (size_t k_1__ = 0; k_1__ < NegPools_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < NegPools_k_0_max__; ++k_0__) {
                    NegPools[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t NegPools_i_0_max__ = N;
            size_t NegPools_i_1_max__ = G;
            for (size_t i_0__ = 0; i_0__ < NegPools_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < NegPools_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "NegPools[i_0__][i_1__]", NegPools[i_0__][i_1__], 0);
                }
            }
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "A", "int", context__.to_vec());
            A = int(0);
            vals_i__ = context__.vals_i("A");
            pos__ = 0;
            A = vals_i__[pos__++];
            check_greater_or_equal(function__, "A", A, 1);
            current_statement_begin__ = 8;
            validate_non_negative_index("MM", "G", G);
            validate_non_negative_index("MM", "A", A);
            context__.validate_dims("data initialization", "MM", "matrix_d", context__.to_vec(G,A));
            MM = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(G, A);
            vals_r__ = context__.vals_r("MM");
            pos__ = 0;
            size_t MM_j_2_max__ = A;
            size_t MM_j_1_max__ = G;
            for (size_t j_2__ = 0; j_2__ < MM_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < MM_j_1_max__; ++j_1__) {
                    MM(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            // initialize transformed data variables
            current_statement_begin__ = 11;
            validate_non_negative_index("TotPools", "N", N);
            validate_non_negative_index("TotPools", "G", G);
            TotPools = std::vector<std::vector<int> >(N, std::vector<int>(G, int(0)));
            stan::math::fill(TotPools, std::numeric_limits<int>::min());
            // execute transformed data statements
            current_statement_begin__ = 12;
            for (int n = 1; n <= N; ++n) {
                current_statement_begin__ = 13;
                for (int g = 1; g <= G; ++g) {
                    current_statement_begin__ = 14;
                    stan::model::assign(TotPools, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_uni(g), stan::model::nil_index_list())), 
                                (get_base1(get_base1(NegPools, n, "NegPools", 1), g, "NegPools", 2) + get_base1(get_base1(PosPools, n, "PosPools", 1), g, "PosPools", 2)), 
                                "assigning variable TotPools");
                }
            }
            // validate transformed data
            current_statement_begin__ = 11;
            size_t TotPools_i_0_max__ = N;
            size_t TotPools_i_1_max__ = G;
            for (size_t i_0__ = 0; i_0__ < TotPools_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < TotPools_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "TotPools[i_0__][i_1__]", TotPools[i_0__][i_1__], 0);
                }
            }
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 19;
            validate_non_negative_index("alpha", "A", A);
            num_params_r__ += A;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_BayesianPoolScreenGeneralised() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 19;
        if (!(context__.contains_r("alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        validate_non_negative_index("alpha", "A", A);
        context__.validate_dims("parameter initialization", "alpha", "vector_d", context__.to_vec(A));
        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha(A);
        size_t alpha_j_1_max__ = A;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            alpha(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 19;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.vector_constrain(A, lp__);
            else
                alpha = in__.vector_constrain(A);
            // transformed parameters
            current_statement_begin__ = 22;
            validate_non_negative_index("p", "G", G);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> p(G);
            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p, DUMMY_VAR__);
            stan::math::assign(p,inv_logit(multiply(MM, alpha)));
            current_statement_begin__ = 23;
            validate_non_negative_index("ps", "N", N);
            validate_non_negative_index("ps", "G", G);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> ps(N, G);
            stan::math::initialize(ps, DUMMY_VAR__);
            stan::math::fill(ps, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 24;
            for (int n = 1; n <= N; ++n) {
                current_statement_begin__ = 25;
                for (int g = 1; g <= G; ++g) {
                    current_statement_begin__ = 26;
                    stan::model::assign(ps, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_uni(g), stan::model::nil_index_list())), 
                                (1 - pow((1 - get_base1(p, g, "p", 1)), get_base1(PoolSizes, n, "PoolSizes", 1))), 
                                "assigning variable ps");
                }
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 22;
            size_t p_j_1_max__ = G;
            for (size_t j_1__ = 0; j_1__ < p_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(p(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: p" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable p: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            check_greater_or_equal(function__, "p", p, 0);
            check_less_or_equal(function__, "p", p, 1);
            current_statement_begin__ = 23;
            size_t ps_j_1_max__ = N;
            size_t ps_j_2_max__ = G;
            for (size_t j_1__ = 0; j_1__ < ps_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < ps_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(ps(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: ps" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable ps: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }
            check_greater_or_equal(function__, "ps", ps, 0);
            check_less_or_equal(function__, "ps", ps, 1);
            // model body
            current_statement_begin__ = 31;
            for (int n = 1; n <= N; ++n) {
                current_statement_begin__ = 32;
                lp_accum__.add(binomial_log<propto__>(stan::model::rvalue(PosPools, stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "PosPools"), stan::model::rvalue(TotPools, stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "TotPools"), stan::model::rvalue(ps, stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "ps")));
            }
            current_statement_begin__ = 34;
            lp_accum__.add(normal_log<propto__>(alpha, 0, 1));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha");
        names__.push_back("p");
        names__.push_back("ps");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(A);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(G);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dims__.push_back(G);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_BayesianPoolScreenGeneralised_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha = in__.vector_constrain(A);
        size_t alpha_j_1_max__ = A;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            vars__.push_back(alpha(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 22;
            validate_non_negative_index("p", "G", G);
            Eigen::Matrix<double, Eigen::Dynamic, 1> p(G);
            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p, DUMMY_VAR__);
            stan::math::assign(p,inv_logit(multiply(MM, alpha)));
            current_statement_begin__ = 23;
            validate_non_negative_index("ps", "N", N);
            validate_non_negative_index("ps", "G", G);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> ps(N, G);
            stan::math::initialize(ps, DUMMY_VAR__);
            stan::math::fill(ps, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 24;
            for (int n = 1; n <= N; ++n) {
                current_statement_begin__ = 25;
                for (int g = 1; g <= G; ++g) {
                    current_statement_begin__ = 26;
                    stan::model::assign(ps, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_uni(g), stan::model::nil_index_list())), 
                                (1 - pow((1 - get_base1(p, g, "p", 1)), get_base1(PoolSizes, n, "PoolSizes", 1))), 
                                "assigning variable ps");
                }
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 22;
            check_greater_or_equal(function__, "p", p, 0);
            check_less_or_equal(function__, "p", p, 1);
            current_statement_begin__ = 23;
            check_greater_or_equal(function__, "ps", ps, 0);
            check_less_or_equal(function__, "ps", ps, 1);
            // write transformed parameters
            if (include_tparams__) {
                size_t p_j_1_max__ = G;
                for (size_t j_1__ = 0; j_1__ < p_j_1_max__; ++j_1__) {
                    vars__.push_back(p(j_1__));
                }
                size_t ps_j_2_max__ = G;
                size_t ps_j_1_max__ = N;
                for (size_t j_2__ = 0; j_2__ < ps_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < ps_j_1_max__; ++j_1__) {
                        vars__.push_back(ps(j_1__, j_2__));
                    }
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_BayesianPoolScreenGeneralised";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_1_max__ = A;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t p_j_1_max__ = G;
            for (size_t j_1__ = 0; j_1__ < p_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t ps_j_2_max__ = G;
            size_t ps_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < ps_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < ps_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "ps" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_1_max__ = A;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t p_j_1_max__ = G;
            for (size_t j_1__ = 0; j_1__ < p_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t ps_j_2_max__ = G;
            size_t ps_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < ps_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < ps_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "ps" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_BayesianPoolScreenGeneralised_namespace::model_BayesianPoolScreenGeneralised stan_model;
#endif
