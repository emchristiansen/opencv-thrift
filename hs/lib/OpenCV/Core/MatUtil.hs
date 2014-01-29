module OpenCV.Core.MatUtil 
  ( module Mat_Consts
  , module Mat_Types
  , module MatUtil_Consts
  , module MatUtil_Types
  , IsProtocol
  , cast
  {-, MatUtil-}
  ) where
  

{-import Thrift-}
import Thrift.Protocol.Binary
{-import Thrift.Transport-}
import Thrift.Transport.Handle
{-import Thrift.Server-}
{-import qualified GHC.IO.Handle.Types-}

{-import Internal.Util-}

import Mat_Consts
import Mat_Types
import MatUtil_Consts
import MatUtil_Types

import qualified MatUtil_Client

class IsProtocol a where
  cast :: BinaryProtocol a => a

{-class Grr a where-}
  {-cast :: BinaryProtocol a => a-}

{-pack :: a -> CVType -> MatUnpacked -> IO Mat-}
{-pack :: forall a. (BinaryProtocol a, Grr a) => a -> CVType -> MatUnpacked -> IO Mat-}
pack protocol = MatUtil_Client.pack $ cast protocol

{-class Bar a where-}
  {-bar :: a -> String-}

{-class Foo a where-}
  {-foo :: Bar a => a -> Int-}

{-grr :: Protocol a => String-}
{-grr = undefined-}

{-data RefinedProtocol a = Thrift.Protocol.Protocol a => RefinedProtocol a-}
{-data RefinedProtocol a = Foo a => RefinedProtocol a-}

{-data MatUtilClient = MatUtilClient Client-}

{-class MatUtil a where-}
  {-pack :: (RefinedProtocol a) -> CVType -> MatUnpacked -> IO Mat -}
  {-pack (RefinedProtocol protocol) = MatUtil_Client.pack protocol-}
