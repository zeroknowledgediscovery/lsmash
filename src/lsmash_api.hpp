#pragma once

#include <string>
#include <vector>
#include "semantic.h"

struct LsmashOptions {
    std::string data_dir = "row";          // row|column|across|up
    std::string data_type = "symbolic";    // symbolic|continuous
    unsigned int data_len = 10000000;
    std::vector<double> partition;          // only used for continuous input
    bool use_derivative = false;            // only used for continuous input
    bool sae = true;
    unsigned int num_repeat = 20;
    unsigned int depth = 8;
};

matrix_dbl lsmash_from_file(const std::string& seqfile, const LsmashOptions& opt);
matrix_dbl lsmash_from_sequences(std::vector<symbol_list_>& seqs, const LsmashOptions& opt);

// Uses the original native llk_distance(sequences, learned_PFSAs) kernel;
// only the PFSA projection family is supplied externally.
matrix_dbl lsmash_from_sequences_with_pfsas(
    std::vector<symbol_list_>& seqs,
    const std::vector<std::string>& pfsa_files,
    const LsmashOptions& opt);
