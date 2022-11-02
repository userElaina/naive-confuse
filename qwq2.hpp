#pragma once

#include "base.hpp"

const int BUF_SIZE = 1 << 24;
const char *ext = ".qwq2";

inline void encode(
    std::string input,
    std::string output,
    std::string key) {
    FILE *i = fopen(input.c_str(), "rb");
    if (!i) {
        throws("Input file not exist!\n");
    }

    if (!output.length()) {
        if (endswith(input, ext)) {
            output = input.substr(0, input.length() - 5);
        } else {
            output = input + ext;
        }
    }
    FILE *o = fopen(output.c_str(), "wb");

    const char *_k = "M%\xd5\xb8\xb0\x14\xcaw\xeb?+A\xb2a\xb0\xc9\xea\xa4]\xb6\xf6\x8c\xd0n\xaa\x87\xc8\xcc\xe3\xe63x\xef";
    if (key.length()) {
        _k = key.c_str();
    }
    const int kl = strlen(_k);
    B *k = (B *)_k;

#ifdef DEBUG
    printf("Encoding / Decoding '%s' to '%s' ...\n", input.c_str(), output.c_str());
#endif

    B *buf = (B *)malloc(BUF_SIZE);
    B *p1 = buf;
    B *p2 = buf + fread(buf, 1, BUF_SIZE, i);

    for (
        int j = kl - 1;
        !(p1 == p2 && ((fwrite(buf, 1, p2 - buf, o), p2 = (p1 = buf) + fread(buf, 1, BUF_SIZE, i)), p1 == p2));
        *p1++ ^= k[j = (j + 1) ^ kl ? j + 1 : 0])
        ;

    printf("Successfully encoded / decoded '%s' to '%s' !\n", input.c_str(), output.c_str());
}
