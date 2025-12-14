#include "4887766_MD2_Task4_DiagnosticRunner.h"

int main()
{
    //creating objects
    std::unique_ptr<DiagnosticTask> ecu = std::make_unique<ECUDiagnostic>("EngineControl");
    std::unique_ptr<DiagnosticTask> sensor = std::make_unique<SensorDiagnostic>(4);

    //assigning tasks to runner
    DiagnosticRunner runner;
    runner.addTask(std::move(ecu));
    runner.addTask(std::move(sensor));

    //executing tasks via runner
    std::vector<std::pair<std::string, std::string>> result = runner.executeAll();

    for(auto& [str, type] : result){
        std::cout<<str<<", "<<type<<std::endl;
    }

    return 0;
}