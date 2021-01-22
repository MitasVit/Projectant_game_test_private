#ifndef MY_OSTREAM_H
#define MY_OSTREAM_H


#include <iostream>
#include <vector>

using namespace std;

template<typename Ch, typename Traits = char_traits<Ch>,
         typename Sequence = vector<Ch> >
struct basic_seqbuf : basic_streambuf<Ch, Traits> {
     typedef basic_streambuf<Ch, Traits> base_type;
     typedef typename base_type::int_type int_type;
     typedef typename base_type::traits_type traits_type;

     virtual int_type overflow(int_type ch) {
         if(traits_type::eq_int_type(ch, traits_type::eof()))
             return traits_type::eof();
         c.push_back(traits_type::to_char_type(ch));
         return ch;
     }

    Sequence const& get_sequence() const {
        return c;
    }
protected:
    Sequence c;
};

// convenient typedefs
typedef basic_seqbuf<char> seqbuf;
typedef basic_seqbuf<wchar_t> wseqbuf;

#endif // MY_OSTREAM_H
