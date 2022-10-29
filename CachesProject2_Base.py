import m5
from m5.objects import Cache

#Add common scripts
m5.util.addToPath('../../')

from common import SimpleOpts

#create L1 cache object
class L1Cache(Cache):

   assoc = 1
   tag_latency = 2
   data_latency = 2
   response_latency = 2
   mshrs = 4
   tgts_per_mshr = 20

   def __init__(self, options=None):
       super(L1Cache, self).__init__()
       pass	

   def connectBus(self, bus):
       raise NotImplementedError

class L1ICache(L1Cache):

   size = '32kB'

   SimpleOpts.add_option('--l1i_size',
			help="L1 instruction cache size. Default: %s" % size)

   def __init__(self, opts=None):
       super(L1ICache, self).__init__(opts)
       if not opts or not opts.l1i_size:
           return 
       self.size = opts.l1i_size

   def connectCPU(self, cpu):
       self.cpu_side = cpu.icache_port

class L1DCache(L1Cache):

   assoc = 1

   size = '64kB'

   SimpleOpts.add_option('--l1d_size',
			help="L1 data cache size. Default: %s" % size)

   def __init__(self, opts=None):
       super(L1DCache, self).__init__(opts)
       if not opts or not opts.l1d_size:
           return
       self.size = opts.l1d_size

   def connectCPU(self, cpu):
       self.cpu_side = cpu.dcache_port

class L2Cache(Cache):

   size = '4MB'
   assoc = 8
   tag_latency = 20
   data_latency = 20
   response_latency = 20
   mshrs = 20
   tgts_per_mshr = 12

   SimpleOpts.add_option('--l2_size', help="L2 cache size. Default: %s" % size)

   def __init__(self, opts=None):
       super(L2Cache, self).__init__()
       if not opts or not opts.l2_size: 
           return
       self.size = opts.l2_size

   def connectCPUSideBus(self, bus):
       self.cpu_side = bus.mem_side_ports

   def connectMemSideBus(self, bus):
       self.mem_side = bus.cpu_side_ports


