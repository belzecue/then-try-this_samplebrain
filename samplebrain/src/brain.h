#include <vector>
#include <string>
#include "jellyfish/core/types.h"
#include "jellyfish/fluxa/sample.h"
#include "brain_block.h"

#ifndef BRAIN
#define BRAIN

namespace spiralcore {

class brain {
public:
    brain();

    // rewrites whole brain
    void init(u32 block_size, u32 overlap);

    // load, chop up and add to brain
    // todo: add tags
    sample load_sound(std::string filename);

    // take another brain and rebuild this brain from bits of that one
    // (presumably this one is made from a single sample)
    sample resynth(const brain &other, float ratio);

    static bool unit_test();

private:

    u32 search(const brain_block &target, float ratio);
    void chop_and_add(const sample &s, u32 block_size, u32 overlap);

    vector<brain_block> m_blocks;
    vector<sample> m_samples;

};

#endif

}