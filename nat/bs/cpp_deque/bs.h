#include <cstdint>
#include <cstdlib>
#include <deque>
#include <map>
#include <optional>
#include <iostream>
#include <ctime>
#include <deque>


std::optional<std::uint64_t> bs(const std::uint64_t &arg1, std::deque<std::uint64_t> arg2) {
    // bs x [] = None
    if (arg2.empty()) {
        return std::optional<std::uint64_t>();
    }

    // bs x [y] = If (x = y) (Some 0) None
    if (arg2.size() == 1) {
        auto x = arg1;
        auto y = arg2[0];
        std::optional<std::uint64_t> temp2;
        if (x == y) {
            temp2 = std::make_optional<std::uint64_t>(0);
        } else {
            temp2 = std::optional<std::uint64_t>();
        }
        return temp2;
    }

    // bs x ys = (let m = (length ys) div 2 in ...
    auto x = arg1;
    auto ys = std::move(arg2);
    auto temp0 = ys.size() / 2;
    auto m = temp0;
    auto temp4 = ys;
    auto temp3 = temp4[m];
    auto y = temp3;
    std::optional<std::uint64_t> temp7;
    if (y == x) {
        temp7 = std::make_optional<std::uint64_t>(m);
    } else {
        std::optional<std::uint64_t> temp10;
        if (y < x) {
            auto temp11 = ([&] {
                auto temp14 = m + 1;
                auto temp15 = std::move(ys);
                temp15.erase(temp15.begin(), std::next(temp15.begin(), temp14));
                auto temp16 = bs(x, std::move(temp15));

                // Some n \<Rightarrow> Some (m + n + 1)
                if (temp16.has_value()) {
                    auto n = temp16.value();
                    return std::make_optional<std::uint64_t>((m + n) + 1);
                }

                // None \<Rightarrow> None
                return std::optional<std::uint64_t>();
            })();
            temp10 = temp11;
        } else {
            auto temp23 = m;
            auto temp24 = std::move(ys);
            temp24.erase(std::next(temp24.begin(), temp23), temp24.end());
            temp10 = bs(x, std::move(temp24));
        }
        temp7 = temp10;
    }
    return temp7;
}


// std::optional<std::uint64_t> bs(std::uint64_t arg1, std::deque<std::uint64_t> arg2) {
//     // bs x [] = None
//     if (arg2.empty()) {
//         return std::optional<std::uint64_t>();
//     }

//     // bs x [y] = If (x = y) (Some Zero) None
//     if (arg2.size() == 1) {
//         auto x = arg1;
//         auto y = arg2[0];
//         std::optional<std::uint64_t> temp0;
//         if (x == y) {
//             temp0 = std::make_optional<std::uint64_t>(0);
//         } else {
//             temp0 = std::optional<std::uint64_t>();
//         }
//         return temp0;
//     }

//     // bs x ys = (let m = (length ys) div 2 in ...
//     auto x = arg1;
//     auto ys = arg2;
//     auto temp0 = ys.size() / 2;
//     auto m = temp0;
//     auto temp2 = ys;
//     auto temp1 = temp2[m];
//     auto y = temp1;
//     std::optional<std::uint64_t> temp3;
//     if (y == x) {
//         temp3 = std::make_optional<std::uint64_t>(m);
//     } else {
//         std::optional<std::uint64_t> temp4;
//         if (y < x) {
//             auto temp5 = ([&] {
//                 auto temp6 = bs(x, std::deque<std::uint64_t>(ys.begin() + m + 1, ys.end()));

//                 // Some n \<Rightarrow> Some (m + n + 1)
//                 if (temp6.has_value()) {
//                     auto n = temp6.value();
//                     return std::make_optional<std::uint64_t>((m + n) + 1);
//                 }

//                 // None \<Rightarrow> None
//                 return std::optional<std::uint64_t>();
//             })();
//             temp4 = temp5;
//         } else {
//             temp4 = bs(x, std::deque<std::uint64_t>(ys.begin(), ys.begin() + m));
//         }
//         temp3 = temp4;
//     }
//     return temp3;
// }