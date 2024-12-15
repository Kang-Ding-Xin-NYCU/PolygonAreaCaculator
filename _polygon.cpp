#include "_polygon.hpp"

polygon::polygon()
{
    calculate_area();
}

polygon::polygon(std::vector<std::vector<double>> input)
{
    vertices = input;
    num = vertices.size();
    calculate_area();
}

polygon::polygon(const polygon& other) {
    this->vertices = other.vertices;
    this->area = other.area;
    if (other.islands.has_value()) {
        this->islands = std::make_optional<std::vector<polygon>>();
        for (const auto& island : other.islands.value()) {
            this->islands->emplace_back(island); // 深拷貝每個嵌套島嶼
        }
    }
}


polygon::~polygon()
{
    vertices.clear();
}

polygon& polygon::operator=(const polygon& other) {
    if (this != &other) {
        this->vertices = other.vertices;
        this->area = other.area;
        if (other.islands.has_value()) {
            this->islands = std::make_optional<std::vector<polygon>>();
            for (const auto& island : other.islands.value()) {
                this->islands->emplace_back(island);
            }
        } else {
            this->islands.reset();
        }
    }
    return *this;
}

std::vector<double> const & polygon::operator() (std::size_t t) const
{
    return vertices.at(t);
}

std::vector<double> & polygon::operator() (std::size_t t)
{
    calculate_area();
    return vertices.at(t);
}

void polygon::set_vertices(std::vector<std::vector<double>> input)
{
    vertices = input;
    num = vertices.size();
    calculate_area();
    return;
}

std::vector<std::vector<double>> polygon::get_vertices() const
{
    return vertices;
}

void polygon::set_islands(std::vector<polygon> input)
{
    islands = std::make_optional<std::vector<polygon>>(input);
    calculate_area();
    std::cout << "Set islands for polygon. Total islands: " << islands->size() << "\n";
    for (const auto& island : islands.value())
    {
        std::cout << "Island vertices: ";
        island.print_vertices();
        if (island.get_islands().has_value())
        {
            std::cout << "Nested islands found.\n";
            for (const auto& nested : island.get_islands().value())
            {
                std::cout << "Nested island vertices: ";
                nested.print_vertices();
            }
        }
    }
    return;
}

std::optional<std::vector<polygon>> polygon::get_islands() const
{
    if (islands.has_value())
    {
        // Debug 信息
        std::cout << "Get islands. Total islands: " << islands->size() << "\n";
        for (const auto& island : islands.value())
        {
            std::cout << "Island vertices: ";
            island.print_vertices();
            if (island.get_islands().has_value())
            {
                std::cout << "Nested islands found.\n";
                for (const auto& nested : island.get_islands().value())
                {
                    std::cout << "Nested island vertices: ";
                    nested.print_vertices();
                }
            }
        }
        return islands;
    }
    return {};
}

double polygon::get_area() const
{
    return area;
}

void polygon::print_vertices() const
{
    for(size_t i = 0; i < num; ++i)
    {
        std::cout << "(" << vertices[i][0] << "," << vertices[i][1] << ")";
    }
    std::cout << "\n" ;
    if (islands.has_value())
    {
        std::cout << "Islands:\n";
        size_t island_index = 1;
        for (const auto& island : islands.value())
        {
            std::cout << "Island " << island_index++ << " Vertices:\n";
            island.print_vertices();
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "No Islands.\n";
    }
    return;
}

void polygon::print_area() const
{
    std::cout << area << "\n";
    return;
}

void polygon::calculate_area()
{
    double sum = 0;
    for(size_t i = 0; i < num; ++i)
    {
        sum += vertices[i % num][0] * vertices[(i + 1) % num][1] - vertices[(i + 1) % num][0] * vertices[i % num][1];
    }
    area = std::abs(sum / 2);
    if(islands.has_value())
    {
        for (const auto& island : islands.value())
        {
            double island_area = island.get_area();
            area = area - island_area;
        }
    }
    return;
}

size_t polygon::size()
{
    return int(num);
}