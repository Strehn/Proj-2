#import m5 library and SimObjects
import m5
from m5.objects import *

#import new Caches
from newcaches import *  

#import argparse
import argparse

parser=argparse.ArgumentParser(description='A simple system with 2-leel cache.')

#add common options for Clock Speed
def addCommonOptions(parser):
    parser.add_argument("--cpu-clock", action="store", type=str,
    default='1GHz', 
    help="Clock for blocks running at CPU speed.") 

parser.add_argument("binary", default="", nargs="?", type=str,
		    help="Path to the binary to execute.")
parser.add_argument("--l1i_size",
                    help=f"L1 cache size. Default 32kB.")
parser.add_argument("--l1d_size",
                    help="L1 data cache size. Default: 64kB.")
parser.add_argument("--l2_size",
		    help="L2 cache size. Default: 4MB.")

options = parser.parse_args()

#create our system object
system = System()

#set the clock time and voltage
system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain()

#set system memory
system.mem_mode = 'timing'
system.mem_ranges = [AddrRange('512MB')]

#set up CPU
system.cpu = O3CPU()

#create memory bus
system.membus = SystemXBar()

#Create a simple cache
system.cache = SimpleCache(size='1kB')

#connect I and D caceh ports of CPU to memo object
system.cpu.icache_port = system.cache.cpu_side
system.cpu.dcache_port = system.cache.cpu_side

#hook cache to memory bus
system.cache.mem_side = system.membus.cpu_side_ports

#create interrupt controller for cpu and connect to membus
system.cpu.createInterruptController()
system.cpu.interrupts[0].pio = system.membus.mem_side_ports
system.cpu.interrupts[0].int_requestor = system.membus.cpu_side_ports
system.cpu.interrupts[0].int_responder = system.membus.mem_side_ports

#create memory controller and connect to membus
system.mem_ctrl = MemCtrl()
system.mem_ctrl.dram = DDR3_2133_8x8()
system.mem_ctrl.dram = LPDDR2_S4_1066_1x32()

system.mem_ctrl.dram.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.mem_side_ports

#create process for 'seiveResults'
process = Process()
#grab path to binary
thispath = os.path.dirname(os.path.realpath(__file__))
binpath = os.path.join(thispath, '../../../',
			'configs/tutorial/part1/seiveResult')

#create process and workload
process.cmd = [binpath]
system.cpu.workload = process
system.cpu.createThreads()

system.workload = SEWorkload.init_compatible(binpath)

#set up root SimObject and start simulation
root = Root(full_system = False, system = system)
m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick %i because %s' % (m5.curTick(), exit_event.getCause()))









