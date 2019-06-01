using System;
using System.Collections.Generic;
using System.IO;
using Google.OrTools.LinearSolver;
using Google.OrTools;

namespace ORTools
{
    class Program
    {
        static void Main(string[] args)
        {
            SolveInstance(ReadRPQFile("/home/mrhowever/Programming/Projects/SPD3/Zad6/cmake-build-debug/in50.txt"));
        }

        public static RPQ_Instance ReadRPQFile(String filename)
        {
            TextReader reader = File.OpenText(filename);
            RPQ_Instance instance = new RPQ_Instance();
            instance.jobs = new List<RPQ_Job>();
            
            String line = reader.ReadLine();
            String[] sizes = line.Split(' ');

            int idx = 0;
            while (!int.TryParse(sizes[idx], out instance.numberOfJobs))
            {
                idx++;
            }

            Console.Write("Size = " + instance.numberOfJobs + "\n");
            
            for (int i = 0; i < instance.numberOfJobs; i++)
            {
                RPQ_Job job = new RPQ_Job();
                line = reader.ReadLine();
                String[] values = line.Split(' ');

                idx = 0;
                for (; !int.TryParse(values[idx], out job.r); idx++)
                {
                }

                idx++;
                
                for (; !int.TryParse(values[idx], out job.p); idx++)
                {
                }

                idx++;
                
                for (; !int.TryParse(values[idx], out job.q); idx++)
                {
                }

                job.id = i;
                
                instance.jobs.Add(job);
            }

            return instance;
        }
        
        public static void SolveInstance(RPQ_Instance instance)
        {
            Solver solver = Solver.CreateSolver("SimpleMipProgram", "CBC_MIXED_INTEGER_PROGRAMMING");

            int variablesMaxValue = 0;
            foreach (RPQ_Job job in instance.jobs)
            {
                variablesMaxValue += job.r + job.p + job.q;
            }

            Console.WriteLine("varmaxval = " + variablesMaxValue);
            
            var alfas = solver.MakeIntVarMatrix(instance.numberOfJobs, instance.numberOfJobs, 0, 1);
            var starts = solver.MakeIntVarArray(instance.numberOfJobs, 0, variablesMaxValue);
            var cmax = solver.MakeIntVar(0, variablesMaxValue, "cmax");

            foreach (RPQ_Job job in instance.jobs)
            {
                solver.Add(starts[job.id] >= job.r);
            }
            
            foreach (RPQ_Job job in instance.jobs)
            {
                solver.Add(cmax >= starts[job.id] + job.p + job.q);
            }
            
            for (int i = 0; i < instance.jobs.Count; i++)
            {
                for (int j = i + 1; j < instance.jobs.Count; j++)
                {
                    var job1 = instance.jobs[i];
                    var job2 = instance.jobs[j];

                    solver.Add(starts[job1.id] + job1.p <= starts[job2.id] +
                               alfas[job1.id, job2.id] * variablesMaxValue);
                    solver.Add(starts[job2.id] + job2.p <= starts[job1.id] +
                               alfas[job2.id, job1.id] * variablesMaxValue);
                    solver.Add(alfas[job1.id, job2.id] + alfas[job2.id, job1.id] == 1);
                }
            }
            
            Console.WriteLine("xddd");
            
            solver.Minimize(cmax);
            Solver.ResultStatus resultStatus = solver.Solve();

            if (resultStatus != Solver.ResultStatus.OPTIMAL)
            {
                Console.WriteLine("Solver didn't find optimal solution!");
            }
            
            Console.WriteLine("Objective value = " + solver.Objective().Value());
        }        
    }
}