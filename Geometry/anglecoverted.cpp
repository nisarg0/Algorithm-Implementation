// original solution in Python with visualization: https://github.com/konradkriehmig/cs-library/tree/main/Topics/3_Programming/DSA/Problems/line_segments
// given question : https://leetcode.com/discuss/interview-question/5567668/Google-Interview-Onsite-1

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>


double get_angle(double x, double y) {
    constexpr double radians_to_degrees = 180.0 / 3.14159265358979323846;
    return std::atan2(x, y) * radians_to_degrees;
}

double positive_modulo(double value, double modulus) {
    return std::fmod(std::fmod(value, modulus) + modulus, modulus);
}

bool can_draw_line(const Case& line_segments) {
    // Transform line segments into ranges of angles.
    std::vector<std::pair<double, double>> angles;
    for (const auto& line : line_segments) {
        double start = get_angle(line.first.x, line.first.y);
        double end = get_angle(line.second.x, line.second.y);
        if (positive_modulo(end - start, 360.0) > 180.0) {
            std::swap(start, end);
        }

        // A straight line is blocked from both directions.
        start = positive_modulo(start, 180.0);
        end = positive_modulo(end, 180.0);
        angles.emplace_back(start, end);
    }

    // Flatten the circle of angles and handle the edge.
    for (std::size_t i = 0; i < angles.size(); ++i) {
        if (angles[i].first > angles[i].second) {
            const double end = angles[i].second;
            angles[i].second = 180.0;
            angles.emplace_back(0.0, end);
        }
    }
    std::sort(angles.begin(), angles.end());

    // See if there is any space to fit a line.
    if (angles.front().first > 0.0 || angles.back().second < 180.0) {
        return true;
    }

    double maximum_end = angles.front().second;
    for (std::size_t i = 0; i + 1 < angles.size(); ++i) {
        if (angles[i].second < angles[i + 1].first &&
            angles[i + 1].first > maximum_end) {
            return true;
        }
        maximum_end = std::max(maximum_end, angles[i].second);
    }
    return false;
}

int main() {
    const std::vector<Case> cases = get_cases();
    for (const auto& line_segments : cases) {
        std::cout << std::boolalpha << can_draw_line(line_segments) << '\n';
    }
}
