#include <CL/sycl.hpp>

// This allow us to remove cl::sycl:: from all invokations
using namespace cl::sycl;

int main() {
    cpu_selector selector;

    queue q(selector);

    std::cout << "Device: " << q.get_device().get_info<info::device::name>()<< std::endl;

    std::cout << "Device vendor: " << q.get_device().get_info<info::device::vendor>()<< std::endl;
    
    std::cout << "Device version: " << q.get_device().get_info<info::device::version>() << std::endl;
    
    std::cout << "Device maximum nº of parallel compute units: " << q.get_device().get_info<info::device::max_compute_units>() << std::endl;
    
    std::cout << "Device maximum work group size used to execute a kernel: " << q.get_device().get_info<info::device::max_work_group_size>() << std::endl;       

    return 0;
}
