module OpenCV.Core.MatUtil 
  ( module Mat_Consts
  , module Mat_Types
  , module MatUtil_Consts
  , module MatUtil_Types
  , IsProtocol
  , cast
  , MatUtil
  ) where
  

{-import Thrift-}
{-import Thrift.Protocol.Binary-}
{-import Thrift.Transport-}
import Thrift.Transport.Handle
{-import Thrift.Server-}
{-import qualified GHC.IO.Handle.Types-}

import Internal.Util

import Mat_Consts
import Mat_Types
import MatUtil_Consts
import MatUtil_Types

import qualified MatUtil_Client

class IsProtocol a where
  cast :: a -> Protocol

{-data MatUtilClient = MatUtilClient Client-}

class IsProtocol a => MatUtil a where
  pack :: a -> CVType -> MatUnpacked -> IO Mat 
  pack protocol = MatUtil_Client.pack $ cast protocol
