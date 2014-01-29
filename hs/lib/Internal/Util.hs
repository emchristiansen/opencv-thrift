module Internal.Util where

{-import Thrift-}
import Thrift.Protocol.Binary
{-import Thrift.Transport-}
{-import Thrift.Transport.Handle-}
{-import Thrift.Server-}
import qualified GHC.IO.Handle.Types

type BinaryProtocolHandle = BinaryProtocol GHC.IO.Handle.Types.Handle

type Protocol = (BinaryProtocolHandle, BinaryProtocolHandle)

